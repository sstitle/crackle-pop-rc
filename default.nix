{
  pkgs ? import <nixpkgs> { },
}:

pkgs.stdenv.mkDerivation {
  pname = "crackle-pop";
  version = "0.1.0";

  src = pkgs.lib.cleanSourceWith {
    src = ./.;
    filter =
      path: type:
      let
        baseName = baseNameOf path;
      in
      !(baseName == "build" || baseName == "result");
  };

  nativeBuildInputs = with pkgs; [
    cmake
    ninja
  ];

  buildInputs = with pkgs; [
    libcxx
  ];

  installPhase = ''
    mkdir -p $out/bin
    cp main $out/bin/crackle-pop
  '';
}
