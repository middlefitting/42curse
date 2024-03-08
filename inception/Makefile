add-host:
	@if ! grep -q "$(USER).42.fr" /etc/hosts; then \
       		echo "Adding $(USER).42.fr to /etc/hosts"; \
        	echo "127.0.0.1 $(USER).42.fr" | sudo tee -a /etc/hosts; \
    	else \
        	echo "$(USER).42.fr already exists in /etc/hosts"; \
    	fi

remove-host:
	@if grep -q "127.0.0.1 $(USER).42.fr" /etc/hosts; then \
        	echo "Removing 127.0.0.1 $(USER).42.fr from /etc/hosts"; \
        	sudo sed -i '/127.0.0.1 $(USER).42.fr/d' /etc/hosts; \
    	else \
        	echo "Entry 127.0.0.1 $(USER).42.fr not found in /etc/hosts"; \
    	fi


all: add-host
	mkdir -p /home/${USER}/data/database
	mkdir -p /home/${USER}/data/website
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

re: down all

clean: 
	docker-compose -f ./srcs/docker-compose.yml down --rmi all
	docker system prune -a -f

fclean: remove-host
	docker-compose -f ./srcs/docker-compose.yml down --rmi all -v
	docker system prune -a -f
	sudo rm -rf /home/${USER}/data

.PHONY	: all down re clean fclean add-host remove-host
