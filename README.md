# crackle-pop-rc

This is an example implementation of "Crackle Pop" a variation of the classic FizzBuzz problem for my Recurse Center application.

I chose to implement this in C++, and I used Nix to provide a reproducible build environment.

I was inspired by this YouTube video on ["Pipeline Oriented Programming"](https://www.youtube.com/watch?v=ipceTuJlw-M).

I really like the monadic syntax of std::expected in C++23, so this is essentially a [port of this code](https://github.com/swlaschin/pipeline_oriented_programming_talk/blob/main/fsharpdemo/FizzBuzzExample_Pipeline.fsx) to C++.

## Setting up Nix

If you've never used Nix before, you can set it up very easily using [Determinate Nix](https://github.com/DeterminateSystems/nix-installer). Run the following command to install Nix:

```bash
curl -fsSL https://install.determinate.systems/nix | sh -s -- install --determinate
```

## Running the program

Once you have Nix installed, simply run this from the repository root:

```bash
nix run
```
