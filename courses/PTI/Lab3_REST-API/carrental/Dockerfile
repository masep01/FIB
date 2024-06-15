FROM node:14

WORKDIR /usr/src/app

COPY package*.json index.html ./

RUN npm install

COPY server.js .

CMD [ "node", "server.js" ]
