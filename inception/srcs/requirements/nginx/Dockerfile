FROM	debian:buster

RUN	apt-get update
RUN	apt-get install -y nginx openssl
RUN	mkdir /etc/nginx/ssl

RUN	openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/nginxssl.crt \
       	-keyout /etc/nginx/ssl/nginxssl.key \
       	-subj "/C=KR/ST=Seoul/L=Seoul/O=42School/OU=Student/CN=sechung/"

COPY	./conf/default.conf /etc/nginx/conf.d/

COPY ./tools/nginx.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/nginx.sh

ENTRYPOINT ["/usr/local/bin/nginx.sh"]

EXPOSE	443

CMD	["nginx", "-g", "daemon off;"]
