cmake_minimum_required(VERSION 2.8)

project(CryptoTool)

aux_source_directory(. VAR)

add_executable(CryptoTool ${VAR})