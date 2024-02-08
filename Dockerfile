FROM nodered/node-red:latest

USER node-red
RUN npm install node-red-contrib-influxdb@0.7.0 node-red-contrib-telegrambot@15.1.8

COPY sf_flows.json /data/sf_flows.json
