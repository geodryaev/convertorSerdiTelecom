FROM debian:11

# Устанавливаем инструменты сборки и Qt-библиотеки
RUN apt update && apt install -y \
    build-essential \
    cmake \
    qtbase5-dev \
    qtbase5-dev-tools \
    libqt5core5a \
    libqt5gui5 \
    libqt5widgets5 \
    qttools5-dev \
    qttools5-dev-tools \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /project

# Копируем весь проект внутрь контейнера
COPY . /project

# Сборка проекта — подкорректируй команду, если используешь qmake или cmake
RUN mkdir build && cd build && cmake .. && make -j$(nproc)

# Контейнер будет запускать твой бинарник по умолчанию (можешь заменить название)
#CMD ["./convertorSerdiTelecom"]
