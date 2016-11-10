#!/bin/bash 

timestamp() {
  date +"%s"
}

./ghr/ghr -t $1 -u Goblenus -r TestReleases timestamp ./Release