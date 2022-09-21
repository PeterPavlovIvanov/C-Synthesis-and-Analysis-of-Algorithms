
using System.Drawing;

namespace BetterCallTaxi
{

    class GlobalConstants
    {
        public static Point START_POINT = new Point(100, 50);
        public static Point START_POINT_LOGOUT = new Point(450, 300);
        public const string CONNECTION_STRING = "Data Source=DESKTOP-PFQL6JD;MultipleActiveResultSets=true;Database=BetterCallTaxi;Integrated Security=True";
        public const string DATE_FORMAT = "yyyy-MM-dd hh:mm:ss.FFF";
        public const string TIME_FORMAT = "hh':'mm':'ss.FFFFFFF";
        public const string TAB = "\t";
        public const string WELCOME_USER = "Welcome, {0}!";
        public const string UNKNOWN = "unknown";
        public const string ADMINISTRATOR = "Administrator";
        public const string DRIVER = "Driver";
        public const string USER = "User";
        public const string DRIVER_AVAILABLE = "Available";
        public const string DRIVER_BUSY = "Busy";
        public const string YES = "Yes";
        public const string NO = "No";
        public const string ORDER_DONE = "Done";
        public const string ORDER_ACTIVE = "Active";
        public const string SUCCESSFULLY_CALLED_TAXI_FROM_TO = "Successfully called taxi from {0} to {1}!\nPlease wait for your car.";

        // Queries
        // Select
        public const string SELECT_CUSTOMER_BY_USERNAME = "SELECT * FROM CUSTOMERS WITH(NOLOCK) WHERE USERNAME = '{0}'";
        public const string SELECT_CUSTOMER_ID_BY_USERNAME = "SELECT ID FROM CUSTOMERS WITH(NOLOCK) WHERE USERNAME = '{0}'";
        public const string SELECT_ORDERS_BEFORE_DATE = "SELECT O.ORD_TIME AS ORD_TIME, C.REG_NOMER AS REG_NOMER, M.NAME AS NAME, ORDERS_COUNTS.COUNTS AS COUNTS\n"
                                                        + "FROM ORDERS AS O WITH(NOLOCK)\n" 
                                                        + "INNER JOIN CARS AS C WITH(NOLOCK) ON C.KOD_TAXI = O.KOD_TAXI\n" 
                                                        + "INNER JOIN MANUFACTURERS AS M WITH(NOLOCK) ON M.ID = C.MANUFACTURER_ID\n" 
                                                        + "INNER JOIN (SELECT KOD_TAXI, COUNT(KOD_TAXI) AS COUNTS\n" 
                                                        + "            FROM ORDERS AS O WITH(NOLOCK)\n" 
                                                        + "            WHERE O.ORD_TIME < CAST('{0}' AS DATETIME) \n" 
                                                        + "            GROUP BY O.KOD_TAXI) AS ORDERS_COUNTS\n" 
                                                        + "            ON C.KOD_TAXI = ORDERS_COUNTS.KOD_TAXI\n" 
                                                        + "WHERE O.ORD_TIME < CAST('{0}' AS DATETIME)\n"; // 3. qryTotalOrders
        public const string SELECT_DRIVER_BY_CUSTOMER_ID = "SELECT * FROM DRIVERS WITH(NOLOCK) WHERE CUSTOMER_ID = {0}";
        public const string SELECT_CUSTOMER_BY_ID = "SELECT * FROM CUSTOMERS WITH(NOLOCK) WHERE ID = {0}";
        public const string SELECT_ALL_ROLES = "SELECT * FROM ROLES WITH(NOLOCK)";
        public const string SELECT_ALL_CUSTOMERS = "SELECT * FROM CUSTOMERS WITH(NOLOCK) ";
        public const string SELECT_DRIVERS_AND_THEIR_NAMES = "SELECT D.ID, D.COMPLETED_ORDERS, D.CUSTOMER_ID, D.MONEY_MADE, D.STATUS, C.NAME\n"
                                                             + " FROM DRIVERS AS D WITH(NOLOCK)\n" 
                                                             + " INNER JOIN CUSTOMERS AS C WITH(NOLOCK)\n"
                                                             + " ON C.ID = D.CUSTOMER_ID";
        public const string SELECT_CARS_AND_OWNERS = "SELECT CAR.KOD_TAXI, CAR.REG_NOMER, M.NAME, CAR.SEATS, CAR.LUGGAGE, C.NAME\n"
                                                    + "FROM CARS AS CAR WITH(NOLOCK)\n"
                                                    + "INNER JOIN MANUFACTURERS AS M WITH(NOLOCK)\n"
                                                    + "ON M.ID = CAR.MANUFACTURER_ID\n"
                                                    + "INNER JOIN DRIVERS AS D WITH(NOLOCK)\n"
                                                    + "ON D.ID = CAR.DRIVER_ID\n"
                                                    + "INNER JOIN CUSTOMERS AS C WITH(NOLOCK)\n"
                                                    + "ON C.ID = D.CUSTOMER_ID\n";
        public static string SELECT_ORDERS_AND_ADD_DATA = "SELECT O.NUM_ORD, CARS.REG_NOMER, M.NAME, O.ADDRESS_FROM, O.ADDRESS_TO, O.ORD_TIME, O.DRIVING_TIME, O.DISTANCE, O.FARE, C.NAME, O.IS_DONE\n"
                                                        + "FROM ORDERS AS O WITH(NOLOCK)                \n"
                                                        + "INNER JOIN CARS WITH(NOLOCK)                 \n"
                                                        + "ON CARS.KOD_TAXI = O.KOD_TAXI                \n"
                                                        + "INNER JOIN MANUFACTURERS AS M WITH(NOLOCK)   \n"
                                                        + "ON M.ID = CARS.MANUFACTURER_ID               \n"
                                                        + "INNER JOIN CUSTOMERS AS C WITH(NOLOCK)       \n"
                                                        + "ON C.ID = O.CUSTOMER_ID \n";
        public static string SELECT_ALL_MANUFACTURERS = "SELECT * FROM MANUFACTURERS WITH(NOLOCK)";
        public static string SELECT_ORDERS_REQUESTS_AND_CUST_NAMES = "SELECT O.ID, C.NAME, O.ADDRESS_FROM, O.ADDRESS_TO, O.ORD_TIME\n"
                                                        + "FROM ORDER_REQUESTS AS O WITH(NOLOCK)        \n"
                                                        + "INNER JOIN CUSTOMERS AS C WITH(NOLOCK)       \n"
                                                        + "ON C.ID = O.CUSTOMER_ID                      \n";
        public static string SELECT_ORDER_REQUESTS_BY_CUSTOMER = "SELECT * FROM ORDER_REQUESTS WITH(NOLOCK) WHERE CUSTOMER_ID = {0}";

        // Update
        public const string UPDATE_CUSTOMER_NAME_AND_USERNAME_BY_ID = "UPDATE CUSTOMERS SET NAME = '{0}', USERNAME = '{1}' WHERE ID = {2}";

        // Insert
        public const string INSERT_CUSTOMER = "INSERT INTO CUSTOMERS VALUES('{0}', '{1}', {2}, {3}, '{4}', HASHBYTES('SHA2_512', '{5}'))";
        public const string INSERT_DRIVER = "INSERT INTO DRIVERS VALUES({0}, {1}, {2}, {3})";
        public const string INSERT_ORDER_REQUEST = "INSERT INTO ORDER_REQUESTS VALUES({0}, '{1}', '{2}', GETDATE())";

        // Procedures
        public const string LOGIN_AUTHENTICATION = "LOGIN_AUTHENTICATION";
        public const string CHECK_USERNAME_AVAILABILITY = "CHECK_USERNAME_AVAILABILITY";

        // User Feedback Messages
        public const string INVALID_CREDENTIALS = "Invalid credentials!";
        public const string USERNAME_TAKEN = "The username: '{0}' is not available!";
        public const string UCN_REQUIRED = "UCN is required.";
        public const string UCN_LENGTH_MESSAGE = "UCN is a 10 digit code.";
        public const string UCN_DIGITS_MESSAGE = "UCN is a 10 digit code.";

        // Codes
        public const int UCN_LENGTH = 10;
        public const int SUCCESSFUL = 1;
        public const int ERROR = 0;
        public const int ERROR_ = -1;

        // Column headers
        // Query 3
        public const string ORDER_TIME = "Date and Time of Order";
        public const string CAR_REG_NUMBER = "Car Register Number";
        public const string MANUFACTURER_NAME = "Car Manufacturer";
        public const string TOTAL_ORDERS_COUNTS = "Total Orders";

        // Customers
        public const string FULL_NAME = "Full Name";
        public const string USERNAME = "USERNAME";
        public const string UCN = "UCN";
        public const string ROLE = "Role";
        public const string ORDERS_MADE = "Total Orders";

        // Drivers
        public const string COMPLETED_ORDERS = "Total Orders Completed";
        public const string MONEY_MADE = "Total Money Made";
        public const string STATUS = "Driver status";

        // Cars
        public const string REG_NOMER = "Car ID";
        public const string MANUFACTURER = "Manufacturer";
        public const string SEATS = "Number of Free Seats";
        public const string LUGAGE = "Lugage space";
        public const string DRIVER_NAME = "Driver";

        // Orders
        public const string ADDRESS_FROM = "Address from";
        public const string ADDRESS_TO = "Address to";
        public const string ORD_TIME = "Date of Order";
        public const string DRIVING_TIME = "Driving Time";
        public const string DISTANCE = "Distance";
        public const string FARE = "Cost";
        public const string IS_DONE = "Order Status";
        public const string CUSTOMER_NAME = "Customer Name";


        public GlobalConstants()
        {

        }
    }
}