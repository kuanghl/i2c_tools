- uninstall

```sh
# if has make uninstall cmds
sudo make uninstall
# if build exist install_manifest.txt files.
sudo xargs rm < install_manifest.txt
# if doesn't exist install_manifest.txt
sudo make install &> make_install.log
# 根据内部的安装文件一个个rm
```