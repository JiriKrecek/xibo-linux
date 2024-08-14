{
  description = "A Nix-flake-based C/C++ development environment";

  inputs.nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.1.*.tar.gz";
  inputs.nixpkgs_gnome.url = "https://github.com/NixOS/nixpkgs/archive/e89cf1c932006531f454de7d652163a9a5c86668.tar.gz";
  inputs.nixpkgs_xorg.url = "https://github.com/NixOS/nixpkgs/archive/515b06ef2ae59b9813b3606888e1791ede8f9090.tar.gz";

  outputs = { nixpkgs,nixpkgs_gnome,nixpkgs_xorg, ... }:
  let
    supportedSystems = [ "x86_64-linux" "aarch64-linux" ];
    forEachSupportedSystem = f: nixpkgs.lib.genAttrs supportedSystems (system: f {
      pkgs = import nixpkgs { inherit system; };
      pkgs_gnome = import nixpkgs_gnome{ inherit system; };
      pkgs_xorg = import nixpkgs_xorg { inherit system; };
    });
  in
  {
    devShells = forEachSupportedSystem ({ pkgs, pkgs_gnome, pkgs_xorg }: {
      default = pkgs.mkShell
      {
        packages = [
          pkgs.cmake
          pkgs.pkg-config
          pkgs.ninja
          pkgs.gcc12
          pkgs.gcc12Stdenv
          pkgs.libstdcxx5
          pkgs.boost175
          pkgs.gtest
          pkgs.sqlite_orm
          pkgs.spdlog
          pkgs.webkitgtk_4_1
          (pkgs.callPackage ./pkgs/cryptopp.nix {})     
          pkgs_gnome.gtkmm3
          pkgs_gnome.glibmm_2_68
          pkgs_gnome.pcre2
          pkgs_gnome.gst_all_1.gst-plugins-base
        ];
      };
    });
  };
}

