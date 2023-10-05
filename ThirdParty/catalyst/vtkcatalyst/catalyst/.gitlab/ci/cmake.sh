#!/bin/sh

set -e

readonly version="3.18.1"
readonly sha256sum="537de8ad3a7fb4ec9b8517870db255802ad211aec00002c651e178848f7a769e"
readonly filename="cmake-$version-Linux-x86_64"
readonly tarball="$filename.tar.gz"

cd .gitlab

echo "$sha256sum  $tarball" > cmake.sha256sum
curl -OL "https://github.com/Kitware/CMake/releases/download/v$version/$tarball"
sha256sum --check cmake.sha256sum
tar xf "$tarball"
mv "$filename" "cmake"
