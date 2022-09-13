
namespace BetterCallTaxi
{

    class GlobalConstants
    {
        public const string CONNECTION_STRING = "Data Source=DESKTOP-PFQL6JD;Database=BetterCallTaxi;Integrated Security=True";

        // Queries
        public const string SELECT_CUSTOMER_BY_USERNAME = "SELECT * FROM CUSTOMERS WITH(NOLOCK) WHERE USERNAME = '{0}'";

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