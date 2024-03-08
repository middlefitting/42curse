#!/bin/sh

set -e

sed -i "s|DOMAIN_NAME|$DOMAIN_NAME|" /etc/nginx/conf.d/default.conf

exec "$@"
