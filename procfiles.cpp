#include "procfiles.h"

QString nameFile(QString path)
{
    return path.mid(path.lastIndexOf('/'),  path.lastIndexOf('.') - path.lastIndexOf('/'))+".csv";
}

void procFile(QString pathToInput, QString PathToOutput)
{
    QVector<QStringList> allString;

    QFile file(pathToInput);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qCritical() << "Не удалось открыть файл:" << pathToInput << file.errorString();
        }

    QTextStream in(&file);
    while (!in.atEnd()) {
           QString line = in.readLine();
           QStringList fields = line.split(';', Qt::SkipEmptyParts);
           allString.push_back(fields);
           /* Пример вывода по полям
           for (int i = 0; i < fields.size(); ++i) {
               qDebug() << "Поле" << i << ":" << fields.at(i).trimmed();
           }
           qDebug() << "-----"; // Разделитель строк
           */
       }
    QFile newFile(PathToOutput+nameFile(pathToInput));
    QStringList head
    {
                     "telco_id",
                     "begin_connection_time",
                     "duration",
                     "call_type_id",
                     "supplement_service_id",
                     "in_abonent_type",
                     "out_abonent_type",
                     "switch_id",
                     "inbound_bunch_type",
                     "inbound_bunch_gsm",
                     "inbound_bunch_mac",
                     "inbound_bunch_vpi",
                     "inbound_bunch_vci",
                     "outbound_bunch_type",
                     "outbound_bunch_gsm",
                     "outbound_bunch_mac",
                     "outbound_bunch_vpi",
                     "outbound_bunch_vci",
                     "term_cause",
                     "phone_card_number",
                     "dialed_digits",
                     "forwarding_identifier",
                     "border_switch_id",
                     "roaming_partner_id",
                     "message",
                     "in_identifier_type",
                     "in_pstn_directory_number",
                     "in_pstn_internal_number",
                     "in_gsm_directory_number",
                     "in_gsm_imsi",
                     "in_gsm_imei",
                     "in_gsm_icc",
                     "in_cdma_directory_number",
                     "in_cdma_imsi",
                     "in_cdma_icc",
                     "in_cdma_esn",
                     "in_cdma_min",
                     "in_voip_ip_address",
                     "in_voip_originator_name",
                     "in_voip_calling_number",
                     "in_begin_location_type",
                     "in_begin_location_mobile_lac",
                     "in_begin_location_mobile_cell",
                     "in_begin_location_mobile_ta",
                     "in_begin_location_wireless_cell",
                     "in_begin_location_wireless_mac",
                     "in_begin_location_geolocation_latitude_grade",
                     "in_begin_location_geolocation_longitude_grade",
                     "in_begin_location_geolocation_projection_type",
                     "in_begin_location_iplocation_ip_address",
                     "in_begin_location_iplocation_ip_port",
                     "in_end_location_type",
                     "in_end_location_mobile_lac",
                     "in_end_location_mobile_cell",
                     "in_end_location_mobile_ta",
                     "in_end_location_wireless_cell",
                     "in_end_location_wireless_mac",
                     "in_end_location_geolocation_latitude_grade",
                     "in_end_location_geolocation_longitude_grade",
                     "in_end_location_geolocation_projection_type",
                     "in_end_location_iplocation_ip_address",
                     "in_end_location_iplocation_ip_port",
                     "out_identifier_type",
                     "out_pstn_directory_number",
                     "out_pstn_internal_number",
                     "out_gsm_directory_number",
                     "out_gsm_imsi",
                     "out_gsm_imei",
                     "out_gsm_icc",
                     "out_cdma_directory_number",
                     "out_cdma_imsi",
                     "out_cdma_icc",
                     "out_cdma_esn",
                     "out_cdma_min",
                     "out_voip_ip_address",
                     "out_voip_originator_name",
                     "out_voip_calling_number",
                     "out_begin_location_type",
                     "out_begin_location_mobile_lac",
                     "out_begin_location_mobile_cell",
                     "out_begin_location_mobile_ta",
                     "out_begin_location_wireless_cell",
                     "out_begin_location_wireless_mac",
                     "out_begin_location_geolocation_latitude_grade",
                     "out_begin_location_geolocation_longitude_grade",
                     "out_begin_location_geolocation_projection_type",
                     "out_begin_location_iplocation_ip_address",
                     "out_begin_location_iplocation_ip_port",
                     "out_end_location_type",
                     "out_end_location_mobile_lac",
                     "out_end_location_mobile_cell",
                     "out_end_location_mobile_ta",
                     "out_end_location_wireless_cell",
                     "out_end_location_wireless_mac",
                     "out_end_location_geolocation_latitude_grade",
                     "out_end_location_geolocation_longitude_grade",
                     "out_end_location_geolocation_projection_type",
                     "out_end_location_iplocation_ip_address",
                     "out_end_location_iplocation_ip_port",
                     "data_content_id",
                     "ss7_opc",
                     "ss7_dpc",
                    };

    if (!newFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical() << "Не удалось сохранить файл: " << PathToOutput+nameFile(pathToInput) << newFile.errorString();
    }
    QTextStream out(&newFile);
    out << head.join(",");
    for (const QStringList el : allString)
    {
        QVector<QString> row;
        row.resize(102);

    }

    newFile.close();




}
