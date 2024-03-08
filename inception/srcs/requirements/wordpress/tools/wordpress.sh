#!/bin/sh

set -e

if [ -f ./wp-config.php ]
then
	echo "wordpress already downloaded"
else
	wp core download --allow-root
	wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_USER_PASSWORD --dbhost=mariadb --allow-root
	wp core install --url=$DOMAIN_NAME --title=$TITLE --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --skip-email --allow-root
	wp user create $USER $USER_EMAIl --user_pass=$USER_PASSWORD --role=author --allow-root
	chown -R www-data:www-data /var/www/html

fi

exec "$@"
