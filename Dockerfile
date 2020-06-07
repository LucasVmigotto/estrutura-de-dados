FROM alpine:latest

RUN apt-get update \
  && apt-get install -f \
  inotify-tools \
  clang \
  clang-tidy \
  gcc \
  g++