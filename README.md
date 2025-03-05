# clone esp-idf from github
mkdir -p ~/esp
cd ~/esp
git clone --recursive https://github.com/espressif/esp-idf.git --branch release/v5.1

# install esp-idf
cd ~/esp/esp-idf
./install.sh

# check version
idf.py --version

# set the default path and easy to build
 ## open bash file 
 nano ~/.bashrc
## add alias to the end of file
alias load_idf='source $HOME/esp/esp-idf/export.sh'

## then reload
source ~/.bashrc

# before using, remember to load
load_idf

# create the project and build
cd ~/esp


idf.py create-project name_project


cd name_project


idf.py set-target esp32s3


idf.py menuconfig  # Để cấu hình thêm nếu cần


idf.py build


idf.py flash -p /dev/ttyUSB0 -b 115200  # Thay đổi port nếu cần


idf.py monitor  # Theo dõi logs
