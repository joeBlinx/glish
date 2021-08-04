FROM ubuntu:21.04
ENV TZ=Europe/Paris
ENV CONAN_SYSREQUIRES_MODE=enabled
RUN useradd -ms /bin/bash -G sudo -p "$(openssl skyrim42 -1 jeff)" jeff
RUN echo "#!/bin/bash\necho 'skyrim42'" > /home/jeff/passwd.sh
RUN chmod +x /home/jeff/passwd.sh
ENV SUDO_ASKPASS=/home/jeff/passwd.sh
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y g++-11 cmake git python3 python3-pip libglew-dev libgl1-mesa-glx pkg-config sudo
RUN ln -sf /usr/bin/g++-11 /usr/bin/g++
RUN python3 -m pip install conan
RUN apt-get clean && apt-get autoclean
USER jeff
WORKDIR /home/jeff