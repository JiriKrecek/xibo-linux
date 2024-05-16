#/bin/bash

curl -o cryptopp.tar.gz -SL https://github.com/weidai11/cryptopp/archive/refs/tags/CRYPTOPP_8_4_0.tar.gz && \
      curl -o cryptopp_pem.zip -SL https://github.com/noloader/cryptopp-pem/archive/095f08ff2ef9bca7b81036a59f2395e4f08ce2e8.zip && \
      tar -zxvf cryptopp.tar.gz && \
      unzip -a cryptopp_pem.zip && \
      cp -r cryptopp-pem-095f08ff2ef9bca7b81036a59f2395e4f08ce2e8/. cryptopp-CRYPTOPP_8_4_0 && \
      cd cryptopp-CRYPTOPP_8_4_0 && \
      make -j4 && \
      sudo make install

cd ..

sudo rm -r ./cryptopp.tar.gz ./cryptopp_pem.zip ./cryptopp-CRYPTOPP_8_4_0/ ./cryptopp-pem-095f08ff2ef9bca7b81036a59f2395e4f08ce2e8/
