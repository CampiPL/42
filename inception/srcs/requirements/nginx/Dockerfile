FROM debian:buster

RUN apt -y update && apt install -y nginx && apt install openssl -y

COPY script.sh .

RUN chmod +x script.sh

CMD [ "./script.sh" ]