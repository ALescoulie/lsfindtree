{
  inputs = {
    naersk.url = "github:nix-community/naersk/master";
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils, naersk }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        naersk-lib = pkgs.callPackage naersk { };
        rustInputs = with pkgs; [ cargo rustc rustfmt pre-commit rustPackages.clippy ];
        cInputs = with pkgs; [ cmake libgcc gdb valgrind gnumake ccls ];
      in
      {
        defaultPackage = naersk-lib.buildPackage ./.;
        devShell = with pkgs; mkShell {
          buildInputs = [rustInputs cInputs];
          RUST_SRC_PATH = rustPlatform.rustLibSrc;
        };
      });
}
