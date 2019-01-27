FROM ubuntu:bionic

RUN apt-get update && apt-get install -y clang libpoco-dev libboost-tools-dev libboost-test-dev libboost-all-dev
