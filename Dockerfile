FROM alpine AS builder
RUN apk add --no-cache gcc libc-dev

WORKDIR /src
ADD main.c ./
RUN gcc -o ahnmika main.c

FROM alpine AS runner
COPY --from=builder /src/ahnmika /bin/ahnmika

CMD ["/bin/ahnmika"]