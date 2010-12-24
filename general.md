#general

##base

sda : scsi disk
filesystem : FAT windows ;EXT linux
linux subregion : / , swap, data, if system breakdown, only format /;
swap : subregion ,no filesystem, virtual memory
Alt+F2 : gconf-editor ; now can add desktop icons / desktop lcons
sudo : change user; root > general; general > root;
sudo apt-get update : update package linking to sever; if packages can't install, it run maybe; 
sudo su : to root mode; ctrl+d or exit quit;
firefox : It's downlowd putting to /tmp;
linux filesystem : tree mode; it not has C,D,E disks, because they are parallel


##chinese input method

sudo apt-get install language-pack-zh
sudo apt-get install language-support-zh
sudo apt-get install fcitx
sudo apt-get install scim

