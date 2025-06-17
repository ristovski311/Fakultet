namespace Extentions
{
    public static class ExtensionMethods
    {
        public static string ShowCurrentTime(this DateTime dt)
        {
            return dt.ToString("dd.MM.yyyy. HH:mm:ss.");
        }
    }
}
