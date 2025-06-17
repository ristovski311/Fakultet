using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;
using Podaci;

namespace Funkcije
{
    public static class Functions
    {
        public static string ConvertToTimerFormat(int num)
        {
            int hours = num / 3600;
            int minutes = (num % 3600) / 60;
            int seconds = num % 60;

            string res = $"{hours} : {minutes} : {seconds}";
            return res;
        }

        public static bool Serialize<T>(this T value, string path)
        {
            if (value == null)
            {
                return false;
            }
            try
            {
                var xmlserializer = new XmlSerializer(typeof(T));

                using (var fileWriter = new FileStream(path, FileMode.Create))
                {
                    xmlserializer.Serialize(fileWriter, value);
                }

                return true;
            }
            catch (Exception ex)
            {
                throw new Exception("Greska pri serijalizaciji!", ex);
            }
        }

        public static T Deserialize<T>(this T value, string path)
        {
            T type;

            var serializer = new XmlSerializer(typeof(T));

            using (var reader = XmlReader.Create(path))
            {
                type = (T)serializer.Deserialize(reader);
            }

            return type;
        }

        public static TablaZaIgru DeserializeFromXml(this TablaZaIgru t,string filePath)
        {
            Type[] extraTypes = { typeof(DimenzijeTable) };

            XmlSerializer serializer = new XmlSerializer(typeof(TablaZaIgru), extraTypes);
            using (FileStream fileStream = new FileStream(filePath, FileMode.Open))
            {
                return (TablaZaIgru)serializer.Deserialize(fileStream);
            }
        }

    }
}
