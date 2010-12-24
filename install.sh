cd src
make
cd ..
echo "Would you like to install to /usr/bin ? Root password will be required. y/n"
read CHOICE
if [ $CHOICE = "y" ]; then
    su -c 'cp simpletron /usr/bin'
fi
