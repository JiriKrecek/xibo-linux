{ lib
, stdenv
, fetchFromGitHub
# Multi-threading with OpenMP is disabled by default
# more info on https://www.cryptopp.com/wiki/OpenMP
, withOpenMP ? false
, llvmPackages
, pkgs
, ...
}:

stdenv.mkDerivation rec {
  pname = "crypto++";
  version = "8.4.0";
  underscoredVersion = lib.strings.replaceStrings ["."] ["_"] version;

  srcs = [
  (fetchFromGitHub {
    owner = "noloader";
    repo = "cryptopp-pem";
    rev = "095f08ff2ef9bca7b81036a59f2395e4f08ce2e8";
    name = "cryptopp-pem";
    hash = "sha256-CV7nHdGOYW9AhGoNaqxUkBUmN420Iw0J1TeylnlDkyo=";
  })
    (fetchFromGitHub {
    owner = "weidai11";
    repo = "cryptopp";
    rev = "CRYPTOPP_${underscoredVersion}";
    name = pname;
    hash = "sha256-gxd3LtvtgwgE1bUQc9pXLT8/WFrQPm3ghIHAGqBHlr8=";
  })
  ];

  outputs = [ "out" "dev" ];

  postPatch = ''
    substituteInPlace GNUmakefile \
      --replace-quiet "AR = /usr/bin/libtool" "AR = ar" \
      --replace-quiet "ARFLAGS = -static -o" "ARFLAGS = -cru"
  '';

  buildInputs = lib.optionals (stdenv.cc.isClang && withOpenMP) [ llvmPackages.openmp ];

  nativeBuildInputs = [pkgs.gcc14];

  preConfigure = "cp ../cryptopp-pem/* .";

  makeFlags = [ "PREFIX=${placeholder "out"}"];

  buildFlags = [
      "static"
      "libcryptopp.pc" ];

  enableParallelBuilding = true;
  hardeningDisable = [ "fortify" ];
  CXXFLAGS = lib.optionals (withOpenMP) [ "-fopenmp" ];

  doCheck = true;

  # always built for checks but install static lib only when necessary
#  preInstall = "rm -f libcryptopp.a";
  
#  postInstall = ''
#        ln -s $out/lib/libcryptopp.so $out/lib/libcryptopp.so.8
#  '';

  installTargets = [ "install-lib" ];
  installFlags = [ "LDCONF=true" ];

  sourceRoot = pname;

  meta = with lib; {
    description = "A free C++ class library of cryptographic schemes";
    homepage = "https://cryptopp.com/";
    changelog = [
      "https://raw.githubusercontent.com/weidai11/cryptopp/CRYPTOPP_${underscoredVersion}/History.txt"
      "https://github.com/weidai11/cryptopp/releases/tag/CRYPTOPP_${underscoredVersion}"
    ];
    license = with licenses; [ boost publicDomain ];
    platforms = platforms.all;
    maintainers = with maintainers; [ c0bw3b ];
  };
}
