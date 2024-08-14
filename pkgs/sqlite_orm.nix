{ pkgs }:
pkgs.stdenv.mkDerivation (finalAttrs: {
  pname = "sqlite_orm";
  version = "1.6";

  src = pkgs.fetchFromGitHub {
    owner = "fnc12";
    repo = "sqlite_orm";
    rev = "${finalAttrs.version}";
    hash = "sha256-KqphGFcnR1Y11KqL7sxODSv7lEvcURdF6kLd3cg84kc=";
  };

  nativeBuildInputs = [
    pkgs.cmake
  ];

  propagatedBuildInputs = [
    pkgs.sqlite
  ];

  strictDeps = true;

  meta = with pkgs.lib; {
    description = "Light header only SQLite ORM";
    homepage = "https://sqliteorm.com/";
    license = licenses.agpl3Only; # MIT license is commercial
    maintainers = with maintainers; [ ambroisie ];
    platforms = platforms.all;
  };
})