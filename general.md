#general

##base

    sda : scsi disk
    filesystem : FAT windows ;EXT linux
    linux subregion : /(sda1) , swap, data(sda2), if system breakdown, only format /;
    subregion : is a hardware theme; / is software theme; subregion has its filesystem; and filesystems are under /;
    swap : subregion ,no filesystem, virtual memory
    Alt+F2 : gconf-editor ; now can add desktop icons / desktop lcons
    sudo : change user; root > general; general > root;
    sudo apt-get update : update package linking to sever; if packages can't install, it run maybe; 
    sudo su : to root mode; ctrl+d or exit quit;
    firefox : It's downlowd putting to /tmp;
    linux filesystem : tree mode; it not has C,D,E disks, because they are parallel
    sda1 : cd / can visit; but sda2, only mount /home , because user has permit to write under /home
    markdown : file.md > file.html, then firefox file.html &;
    shell : sh, csh, bash; but all linux use bash
    copy : only read command; if cp root file to users, only read; buy cp to *.bak, can write

##chinese input method

    sudo apt-get install language-pack-zh
    sudo apt-get install language-support-zh
    sudo apt-get install fcitx
    sudo apt-get install scim
##git


    git-core : data share; CVS SVN; time mathine, commit coltrol
    git commit -a -m "first commit"

    git clone git://github.com......
    git pull; git show; git diff(patch);

    diff x.txt y.txt > xy.diff; diff -u x.txt y.txt > xy.diff
    patch <ab.diff

    ssh-keygen, creat a key, ssh is a key language; 
    cd .ssh; ls; id_rsa, id_rsa.pub;











