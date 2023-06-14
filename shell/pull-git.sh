#!/bin/bash

# 获取当前目录
base_dir=$(pwd)

# 遍历当前目录下的所有目录和下一级子目录
for dir in $(find . -maxdepth 2 -type d); do
  # 切换到目录
  cd "$base_dir/$dir"
  
  # 检查是否为Git项目
  if [ -d .git ]; then
    echo "Pulling latest changes in $dir"
    git pull 
    echo "Finished pulling in $dir"
  fi
done

