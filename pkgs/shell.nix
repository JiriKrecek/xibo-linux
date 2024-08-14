let
pkgs = import (builtins.fetchTarball {
		url = "https://github.com/NixOS/nixpkgs/archive/e89cf1c932006531f454de7d652163a9a5c86668.tar.gz";
		}) {};
pkgs23_11 = import (builtins.fetchTarball {
		url = "https://github.com/NixOS/nixpkgs/archive/refs/tags/23.05.tar.gz";
		}) {};
in

pkgs.mkShellNoCC {
	packages = with pkgs; [
		webkitgtk
			cmake
			ninja
			gcc12
			pkg-config
			gtkmm3
			glibmm_2_68
			pcre2
			glib
			util-linux
			gst_all_1.gst-plugins-base
			vala
			libselinux
			libsepol
			xorg.libXdmcp
			libthai
			libdatrie
			libunwind
			libxkbcommon
			gtest
			libepoxy
			boost184
			xorg.libXtst
			openssl
			libsoup
			cppzmq
			libsysprof-capture
			libpsl
			fmt_9
			elfutils
			orc
			zstd
			libbacktrace
			(callPackage ./sqlite_orm.nix {})
			(callPackage ./cryptopp.nix {})

			#wget
			#curl
			#unzip
			#cacert
			] ++ [
			pkgs23_11.spdlog
			];
}
