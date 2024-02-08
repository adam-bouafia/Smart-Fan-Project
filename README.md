Smart Fan Project - SE4IOT

Introduction :
The Smart Fan project is an innovative IoT solution designed to optimize environmental conditions through real-time temperature and humidity control. Utilizing a Wokwi simulation for development and testing, the system employs MQTT for efficient data transmission from sensors to a Node-RED server.
This data includes temperature, humidity, and dynamically adjusted fan speed, making the fan "smart" by adapting to the current environment.

Academic Context
This Smart Fan project was developed as part of the "Software Engineering for Internet of Things" course at the University of L'Aquila (Univaq).
It serves as a practical application of IoT principles, software engineering practices, and real-world data handling in a connected environment.
Contributions and insights from fellow students and faculty are highly encouraged to foster a collaborative learning experience.

Architecture : 
Wokwi Simulation: Simulates the ESP32-based smart fan, capturing temperature, humidity, and controlling fan speed.
MQTT Broker: Facilitates message passing from the simulated ESP32 to Node-RED.
Node-RED: Processes incoming data for storage and notification.
InfluxDB: Stores time-series data for historical analysis and visualization.
Telegram Bot: Sends real-time alerts based on predefined conditions.
Grafana: Visualizes data stored in InfluxDB for monitoring and analysis.

How It Works:
The ESP32 measures temperature and humidity, adjusting the fan speed accordingly.
Data is sent to Node-RED via MQTT, then to InfluxDB for storage and Telegram for notifications.
Grafana fetches data from InfluxDB, providing a dashboard for real-time and historical data visualization.


Setup and Configuration:
This project leverages Docker to simplify deployment and management of its components. Ensure Docker and Docker Compose are installed on your system before proceeding.

Docker Compose
Clone the project repository to your local machine.
Navigate to the project directory where docker-compose.yml is located.
Run docker-compose up -d to start all services in detached mode. This command pulls necessary images and starts the services defined in docker-compose.yml, including Node-RED, InfluxDB, and Grafana.
Accessing Services
Node-RED: Access the Node-RED editor by navigating to http://localhost:1880 on your web browser.
InfluxDB: InfluxDB UI can be accessed at http://localhost:8086. Use the credentials defined in the environment variables of docker-compose.yml for initial login.
Grafana: Open http://localhost:3000 to access Grafana. Default login is admin/admin. Configure InfluxDB as the data source using the InfluxDB details.
Configuration Details
Node-RED Flow: Import the provided Node-RED flow configuration to set up the data processing pipeline.
Telegram Bot: Ensure the Telegram bot token is correctly configured in your Node-RED flow for notifications.
Grafana Dashboard: Import the Grafana dashboard JSON to visualize temperature, humidity, and fan speed data.
Final Steps
After setting up all services, your Smart Fan project is ready. The system will automatically start collecting data, storing it in InfluxDB, sending notifications through Telegram, and visualizing data in Grafana based on the temperature and humidity readings from your Wokwi simulation.

Contributing:
We welcome contributions to the Smart Fan project! If you have ideas for improvements, bug fixes, or new features, please follow these steps:

Fork the Repository: Start by forking the project repository to your own GitHub account.

Create a Branch: For each new feature or fix, create a new branch from main.

Follow Coding Standards: Ensure your code adheres to the coding standards used throughout the project.

Submit a Pull Request: Once your feature or fix is ready, submit a pull request against the main branch of the original repository.

Issue Reporting: For bugs or feature requests, please open an issue providing as much detail as possible.

License:
This project is the property of Adam-Bouafia and is licensed under the MIT License.
This license allows others to use, modify, and distribute the work, provided they attribute it back to the author. The full license text can be found in the LICENSE file in the project repository.

By contributing to this project, you agree that your contributions will be licensed under its MIT License.

