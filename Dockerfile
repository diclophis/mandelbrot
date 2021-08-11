FROM ubuntu:20.04

ENV LC_ALL C.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8
ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y apache2 apache2-utils libapache2-mod-php
RUN apt-get install -y build-essential libgd-dev libjpeg-dev libpng-dev libz-dev

RUN a2enmod php7.4 headers rewrite expires cache
RUN a2dissite 000-default
RUN echo "Listen 8080" | tee /etc/apache2/ports.conf

ENV APACHE_RUN_USER www-data
ENV APACHE_RUN_GROUP www-data
ENV APACHE_LOG_DIR /var/log/apache2
ENV APACHE_PID_FILE /var/run/apache2.pid
ENV APACHE_LOCK_DIR /var/lock/apache2
ENV APACHE_RUN_DIR /var/run/apache2

RUN echo "ServerName container" > /etc/apache2/sites-available/mandelbrot.conf
RUN a2ensite mandelbrot

ADD src /var/www/html/

RUN cd /var/www/html && bash make.sh

ADD OpenLayers.js generate.php index.html /var/www/html/
ADD theme /var/www/html/theme
ADD img /var/www/html/img

RUN apache2 -t

CMD ["apache2", "-D", "FOREGROUND"]
