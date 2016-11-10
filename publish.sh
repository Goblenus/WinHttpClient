#!/bin/bash 

timestamp() {
  date +"%T"
}

./ghr/ghr -t $1 -u Goblenus -r TestReleases timestamp ./Release