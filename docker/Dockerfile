FROM ubuntu:21.04
ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update
RUN apt-get install -y g++-11 cmake git python3 python3-pip libglew-dev libgl1-mesa-glx
RUN ln -sf /usr/bin/g++-11 /usr/bin/g++
RUN python3 -m pip install conan
RUN apt-get clean && apt-get autoclean