#!/bin/bash

set -e

mysqld_safe &
sleep 2
if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then
	echo "Using Exist DB"
else
	mysql -u root -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; FLUSH PRIVILEGES;"
	mysql -u root -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD'; FLUSH PRIVILEGES;"
	sleep 1
	mysql -u root -e "ALTER USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD'; FLUSH PRIVILEGES;"
	mysql -u root -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'; FLUSH PRIVILEGES;"
	sleep 1
	mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;"
	sleep 1
fi
mysqladmin -u root -p"$MYSQL_ROOT_PASSWORD" shutdown
sleep 2
exec "$@"
