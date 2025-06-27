#!/bin/bash

APP_NAME="convertorSerdiTelecom"
APP_DST_DIR="/opt/$APP_NAME"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
APP_SRC_DIR="$SCRIPT_DIR/$APP_NAME"

BINARY_SCR="./$APP_NAME"
BINARY_DST="$APP_PATH/$APP_NAME"
SERVICE_FILE="/etc/systemd/system/$APP_NAME.service"

read -p "Введите имя пользователя для запуска сервиса (default:user)!NO ROOT!\n" SERVICE_USER

SERVICE_USER=${SERVICE_USER:-user}

if ! id -u "$SERVICE_USER" >/dev/null 2>&1; then
  echo "Пользователь '$SERVICE_USER' не существует. Создайте его или укажите другой."
  exit 1
fi
echo "Используется пользоваетль: '$SERVICE_USER'"

echo "Копируем проект в $APP_DST_DIR..."
sudo rm -rf "$APP_DST_DIR"
sudo mkdir -p "$APP_DST_DIR"
sudo cp -r "$APP_SRC_DIR/"* "$APP_DST_DIR"
sudo chown -R "$SERVICE_USER":"$SERVICE_USER" "$APP_DST_DIR"

echo "Копирование завершено"

if [ ! -f "$APP_DST_DIR/$APP_NAME" ]; then
  echo "Ошибка: бинарный файл '$APP_NAME' не найден в $APP_DST_DIR"
  exit 1
fi

# Создание systemd unit-файла
echo "Создаём systemd сервис..."
sudo bash -c "cat > /etc/systemd/system/$APP_NAME.service" <<EOL
[Unit]
Description=$APP_NAME service
After=network.target

[Service]
Type=simple
ExecStart=$APP_DST_DIR/$APP_NAME
Restart=always
RestartSec=5
User=$SERVICE_USER
WorkingDirectory=$APP_DST_DIR
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target
EOL

# Запуск сервиса
echo "Активируем и запускаем сервис..."
sudo systemctl daemon-reload
sudo systemctl enable "$APP_NAME.service"
sudo systemctl restart "$APP_NAME.service"

echo "$APP_NAME установлен и запущен как systemd-сервис от пользователя $SERVICE_USER."
