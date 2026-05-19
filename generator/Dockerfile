FROM gcc:latest
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -o myapp Passgen.cpp
CMD ["sh", "-c", "./myapp && tail -f /dev/null"]