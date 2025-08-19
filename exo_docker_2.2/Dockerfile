FROM gcc:12.5 AS builder
COPY . /usr/src/fibo
WORKDIR /usr/src/fibo
RUN g++ -O2 -o /bin/fibo ./main.cpp

FROM debian:bookworm-slim
COPY --from=builder /bin/fibo /bin/fibo
CMD ["/bin/fibo"]
