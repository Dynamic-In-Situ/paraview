#!/bin/sh

set -e

readonly version="1.10.0"
readonly sha256sum="6566836ddf3d72ca06685b34814e0c6fa0f0943542d651d0dab3150f10307c82"
readonly filename="ninja-linux.zip"

cd .gitlab

echo "$sha256sum  $filename" > ninja.sha256sum
curl -OL "https://github.com/ninja-build/ninja/releases/download/v$version/$filename"
sha256sum --check ninja.sha256sum
unzip "$filename"
