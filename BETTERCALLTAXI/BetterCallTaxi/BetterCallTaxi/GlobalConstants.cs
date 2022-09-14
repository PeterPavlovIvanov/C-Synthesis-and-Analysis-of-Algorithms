
namespace BetterCallTaxi
{

    class GlobalConstants
    {
        public const string CONNECTION_STRING = "Data Source=DESKTOP-PFQL6JD;Database=BetterCallTaxi;Integrated Security=True";

        // Queries
        public const string SELECT_CUSTOMER_BY_USERNAME = "SELECT * FROM CUSTOMERS WITH(NOLOCK) WHERE USERNAME = '{0}'";
        public const string SELECT_ORDERS_BEFORE_DATE = "SELECT O.ORD_TIME, C.REG_NOMER, M.NAME, ORDERS_COUNTS.COUNTS\n" 
                                                        + "FROM ORDERS AS O WITH(NOLOCK)\n" 
                                                        + "INNER JOIN CARS AS C WITH(NOLOCK) ON C.KOD_TAXI = O.KOD_TAXI\n" 
                                                        + "INNER JOIN MANUFACTURERS AS M WITH(NOLOCK) ON M.ID = C.MANUFACTURER_ID\n" 
                                                        + "INNER JOIN (SELECT KOD_TAXI, COUNT(KOD_TAXI) AS COUNTS\n" 
                                                        + "            FROM ORDERS AS O WITH(NOLOCK)\n" 
                                                        + "            WHERE O.ORD_TIME< '{0}' \n" 
                                                        + "            GROUP BY O.KOD_TAXI) AS ORDERS_COUNTS\n" 
                                                        + "            ON C.KOD_TAXI = ORDERS_COUNTS.KOD_TAXI\n" 
                                                        + "WHERE O.ORD_TIME< '{0}'\n"; // 3. qryTotalOrders

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

        public GlobalConstants()
        {

        }
    }
}