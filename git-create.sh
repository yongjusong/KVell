#!/bin/sh
repo_name=$1
test -z $repo_name && echo "Repo name required." 1>&2 && exit 1
curl -u '[username]:[password]' https://api.github.com/user/repos -d "{\"name\":\"$repo_name\"}"
git init
git add .
git commit -m "initial commit"
git remote add origin "https://github.com/yongjusong/$repo_name.git"
git push -u origin master
