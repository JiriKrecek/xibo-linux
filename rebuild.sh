cd build
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=DEBUG ../player |& tee ./../logBuild.txt && \
cmake --build . -j10 |& tee -a ./../logBuild.txt && \
cmake --install . |& tee -a ./../logBuild.txt 