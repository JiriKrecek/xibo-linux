cd build
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=RELEASE ../player |& tee -a ./../logBuild.txt && \
cmake --build . -j15 |& tee -a ./../logBuild.txt && \
cmake --install . |& tee -a ./../logBuild.txt 
