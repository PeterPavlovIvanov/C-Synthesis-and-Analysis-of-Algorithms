using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class InputValidator
    {
        public InputValidator()
        {

        }

        public static bool Validate_Username(string strUsername)
        {
            if (strUsername == "")
            {
                MessageBox.Show("You must enter a username.");
                return false;
            }

            if (strUsername.Length < 5)
            {
                MessageBox.Show("You must enter a username longer than 4 symbols.");
                return false;
            }

            if (strUsername.Length > 25)
            {
                MessageBox.Show("You must enter a username shorter than 26 symbols.");
                return false;
            }

            return true;
        }

        public static bool Validate_Password(string strPassword, string strRePassword = "", bool bRegister = false)
        {
            if (strPassword == "")
            {
                MessageBox.Show("You must enter a password.");
                return false;
            }

            if (strPassword.Length < 6)
            {
                MessageBox.Show("You must enter a password longer than 5 symbols.");
                return false;
            }

            if (strPassword.Length > 25)
            {
                MessageBox.Show("You must enter a password shorter than 26 symbols.");
                return false;
            }

            if (bRegister)
            {
                if (strRePassword != strPassword)
                {
                    MessageBox.Show("Provided passwords do not match!.");
                    return false;
                }
            }

            return true;
        }



        public static bool Validate_Ucn(string strUcn)
        {
            if (strUcn == "")
            {
                MessageBox.Show(GlobalConstants.UCN_REQUIRED);
                return false;
            }

            if (strUcn.Length != GlobalConstants.UCN_LENGTH)
            {
                MessageBox.Show(GlobalConstants.UCN_LENGTH_MESSAGE);
                return false;
            }

            foreach (char cSymbol in strUcn)
            {
                if (cSymbol < 48 && cSymbol > 57)
                {
                    MessageBox.Show(GlobalConstants.UCN_DIGITS_MESSAGE);
                    return false;
                }
            }

            return true;
        }
    }
}
