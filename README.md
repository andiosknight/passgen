# Passgen & Microservices Stack

Учебный проект по генерации безопасных паролей, развернутый в микросервисной архитектуре с использованием контейнеризации и оркестрации.

## Структура проекта

Проект разделен на три независимых сервиса, взаимодействующих в изолированной сети, и отказоустойчивый веб-сервер:

*   **generator** — основное приложение на C++ (`Passgen.cpp`), генерирующее случайные пароли и оценивающее их сложность.
*   **service1** — имитация микросервиса базы данных (на базе Python), фиксирующего подключения.
*   **service2** — легковесный сервис логирования (на базе Alpine Linux), подтверждающий успешный сбор отчетов.
*   **nginx** — обратный прокси-сервер (Reverse Proxy) для маршрутизации внешнего трафика.

```text
generator/
   Passgen.cpp
   Dockerfile
service1/
    app.py
    Dockerfile
service2/
    Dockerfile
nginx/
    default.conf
docker-compose.yml
```

## Варианты запуска

Перед запуском убедитесь, что у вас установлен **Docker Desktop** и запущен движок Docker.

### Вариант 1: Локальный запуск (Docker Compose)
Используется для быстрой сборки, отладки и проверки логов всех сервисов:

```bash
docker-compose up --build
```

### Вариант 2: Оркестрация и масштабирование (Docker Swarm)
Используется для развертывания отказоустойчивого стека с балансировкой нагрузки через Nginx.

1. Инициализируйте Swarm-кластер (если не сделано ранее):
   ```bash
   docker swarm init
   ```

2. Соберите локальные образы для оркестратора:
   ```bash
   docker build -t my-generator:latest ./generator
   docker build -t my-service1:latest ./service1
   docker build -t my-service2:latest ./service2
   ```

3. Разверните стек сервисов:
   ```bash
   docker stack deploy -c docker-compose.yml my_labs
   ```

4. Проверьте статус реплик и масштабирования:
   ```bash
   docker service ls
   ```

## Технологический стек
*   **Языки:** C++, Python 3.9, Bash / Shell
*   **Контейнеризация:** Docker, Dockerfile
*   **Оркестрация:** Docker Compose, Docker Swarm
*   **Веб-серверы:** Nginx
