#include <windows.h>

static void log_call(const char* fn) {
    OutputDebugStringA(fn);
    OutputDebugStringA("\n");
}

__declspec(dllexport) DWORD ANTFSClient_Cancel(void) {
    log_call("ANTFSClient_Cancel");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_Close(void) {
    log_call("ANTFSClient_Close");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_CloseBeacon(void) {
    log_call("ANTFSClient_CloseBeacon");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_ConfigureClientParameters(void) {
    log_call("ANTFSClient_ConfigureClientParameters");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_Delete(void) {
    log_call("ANTFSClient_Delete");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetChannelNumber(void) {
    log_call("ANTFSClient_GetChannelNumber");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetDisconnectParameters(void) {
    log_call("ANTFSClient_GetDisconnectParameters");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetDownloadStatus(void) {
    log_call("ANTFSClient_GetDownloadStatus");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetEnabled(void) {
    log_call("ANTFSClient_GetEnabled");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetHostName(void) {
    log_call("ANTFSClient_GetHostName");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetRequestParameters(void) {
    log_call("ANTFSClient_GetRequestParameters");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetRequestedFileIndex(void) {
    log_call("ANTFSClient_GetRequestedFileIndex");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetStatus(void) {
    log_call("ANTFSClient_GetStatus");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetTransferData(void) {
    log_call("ANTFSClient_GetTransferData");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetTransferSize(void) {
    log_call("ANTFSClient_GetTransferSize");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_GetVersion(void) {
    log_call("ANTFSClient_GetVersion");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_Init(void) {
    log_call("ANTFSClient_Init");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_New(void) {
    log_call("ANTFSClient_New");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_OpenBeacon(void) {
    log_call("ANTFSClient_OpenBeacon");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_ProcessDeviceNotification(void) {
    log_call("ANTFSClient_ProcessDeviceNotification");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_ProcessMessage(void) {
    log_call("ANTFSClient_ProcessMessage");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SendDownloadResponse(void) {
    log_call("ANTFSClient_SendDownloadResponse");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SendEraseResponse(void) {
    log_call("ANTFSClient_SendEraseResponse");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SendPairingResponse(void) {
    log_call("ANTFSClient_SendPairingResponse");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SendUploadResponse(void) {
    log_call("ANTFSClient_SendUploadResponse");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetBeaconTimeout(void) {
    log_call("ANTFSClient_SetBeaconTimeout");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetChannelID(void) {
    log_call("ANTFSClient_SetChannelID");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetChannelPeriod(void) {
    log_call("ANTFSClient_SetChannelPeriod");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetDataAvailable(void) {
    log_call("ANTFSClient_SetDataAvailable");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetFriendlyName(void) {
    log_call("ANTFSClient_SetFriendlyName");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetNetworkKey(void) {
    log_call("ANTFSClient_SetNetworkKey");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetPairingEnabled(void) {
    log_call("ANTFSClient_SetPairingEnabled");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetPairingTimeout(void) {
    log_call("ANTFSClient_SetPairingTimeout");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetPassKey(void) {
    log_call("ANTFSClient_SetPassKey");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetTxPower(void) {
    log_call("ANTFSClient_SetTxPower");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_SetUploadEnabled(void) {
    log_call("ANTFSClient_SetUploadEnabled");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSClient_WaitForResponse(void) {
    log_call("ANTFSClient_WaitForResponse");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSDirectory_GetNewFileList(void) {
    log_call("ANTFSDirectory_GetNewFileList");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSDirectory_GetNumberOfFileEntries(void) {
    log_call("ANTFSDirectory_GetNumberOfFileEntries");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSDirectory_LookupFileEntry(void) {
    log_call("ANTFSDirectory_LookupFileEntry");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSDirectory_LookupFileIndex(void) {
    log_call("ANTFSDirectory_LookupFileIndex");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_AddSearchDevice(void) {
    log_call("ANTFSHost_AddSearchDevice");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Authenticate(void) {
    log_call("ANTFSHost_Authenticate");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Blackout(void) {
    log_call("ANTFSHost_Blackout");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Cancel(void) {
    log_call("ANTFSHost_Cancel");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_ClearBlackoutList(void) {
    log_call("ANTFSHost_ClearBlackoutList");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_ClearSearchDeviceList(void) {
    log_call("ANTFSHost_ClearSearchDeviceList");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Close(void) {
    log_call("ANTFSHost_Close");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Delete(void) {
    log_call("ANTFSHost_Delete");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Disconnect(void) {
    log_call("ANTFSHost_Disconnect");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Download(void) {
    log_call("ANTFSHost_Download");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_EnablePing(void) {
    log_call("ANTFSHost_EnablePing");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_EraseData(void) {
    log_call("ANTFSHost_EraseData");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetChannelNumber(void) {
    log_call("ANTFSHost_GetChannelNumber");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetDownloadStatus(void) {
    log_call("ANTFSHost_GetDownloadStatus");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetEnabled(void) {
    log_call("ANTFSHost_GetEnabled");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetFoundDeviceChannelID(void) {
    log_call("ANTFSHost_GetFoundDeviceChannelID");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetFoundDeviceParameters(void) {
    log_call("ANTFSHost_GetFoundDeviceParameters");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetStatus(void) {
    log_call("ANTFSHost_GetStatus");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetTransferData(void) {
    log_call("ANTFSHost_GetTransferData");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetTransferSize(void) {
    log_call("ANTFSHost_GetTransferSize");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetUploadStatus(void) {
    log_call("ANTFSHost_GetUploadStatus");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_GetVersion(void) {
    log_call("ANTFSHost_GetVersion");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Init(void) {
    log_call("ANTFSHost_Init");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_New(void) {
    log_call("ANTFSHost_New");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_ProcessDeviceNotification(void) {
    log_call("ANTFSHost_ProcessDeviceNotification");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_ProcessMessage(void) {
    log_call("ANTFSHost_ProcessMessage");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_RemoveBlackout(void) {
    log_call("ANTFSHost_RemoveBlackout");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_RemoveSearchDevice(void) {
    log_call("ANTFSHost_RemoveSearchDevice");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_RequestSession(void) {
    log_call("ANTFSHost_RequestSession");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_SearchForDevice(void) {
    log_call("ANTFSHost_SearchForDevice");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_SetChannelID(void) {
    log_call("ANTFSHost_SetChannelID");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_SetChannelPeriod(void) {
    log_call("ANTFSHost_SetChannelPeriod");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_SetNetworkKey(void) {
    log_call("ANTFSHost_SetNetworkKey");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_SetProximitySearch(void) {
    log_call("ANTFSHost_SetProximitySearch");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_SetSerialNumber(void) {
    log_call("ANTFSHost_SetSerialNumber");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_SwitchFrequency(void) {
    log_call("ANTFSHost_SwitchFrequency");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_Upload(void) {
    log_call("ANTFSHost_Upload");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANTFSHost_WaitForResponse(void) {
    log_call("ANTFSHost_WaitForResponse");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_AddChannelID_RTO(void) {
    log_call("ANT_AddChannelID_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_AddCryptoID_RTO(void) {
    log_call("ANT_AddCryptoID_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_AssignChannelExt_RTO(void) {
    log_call("ANT_AssignChannelExt_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_AssignChannel_RTO(void) {
    log_call("ANT_AssignChannel_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_Close(void) {
    log_call("ANT_Close");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_CloseChannel_RTO(void) {
    log_call("ANT_CloseChannel_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigCryptoList_RTO(void) {
    log_call("ANT_ConfigCryptoList_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigEventBuffer(void) {
    log_call("ANT_ConfigEventBuffer");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigEventFilter(void) {
    log_call("ANT_ConfigEventFilter");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigFrequencyAgility(void) {
    log_call("ANT_ConfigFrequencyAgility");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigHighDutySearch(void) {
    log_call("ANT_ConfigHighDutySearch");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigList_RTO(void) {
    log_call("ANT_ConfigList_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigSelectiveDataUpdate(void) {
    log_call("ANT_ConfigSelectiveDataUpdate");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigUserNVM(void) {
    log_call("ANT_ConfigUserNVM");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigureAdvancedBurst_RTO(void) {
    log_call("ANT_ConfigureAdvancedBurst_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigureAdvancedBurst_ext_RTO(void) {
    log_call("ANT_ConfigureAdvancedBurst_ext_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ConfigureSplitAdvancedBursts(void) {
    log_call("ANT_ConfigureSplitAdvancedBursts");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_CryptoKeyNVMOp_RTO(void) {
    log_call("ANT_CryptoKeyNVMOp_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_CrystalEnable(void) {
    log_call("ANT_CrystalEnable");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_DebugResetTime(void) {
    log_call("ANT_DebugResetTime");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_DebugThreadInit(void) {
    log_call("ANT_DebugThreadInit");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_DebugThreadWrite(void) {
    log_call("ANT_DebugThreadWrite");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_DisableDebugLogging(void) {
    log_call("ANT_DisableDebugLogging");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_EnableDebugLogging(void) {
    log_call("ANT_EnableDebugLogging");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_EnableLED_RTO(void) {
    log_call("ANT_EnableLED_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_EncryptedChannelEnable_RTO(void) {
    log_call("ANT_EncryptedChannelEnable_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetCapabilities(void) {
    log_call("ANT_GetCapabilities");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetChannelID(void) {
    log_call("ANT_GetChannelID");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetChannelNumber(void) {
    log_call("ANT_GetChannelNumber");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetChannelStatus(void) {
    log_call("ANT_GetChannelStatus");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetDeviceSerialNumber(void) {
    log_call("ANT_GetDeviceSerialNumber");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetDeviceSerialString(void) {
    log_call("ANT_GetDeviceSerialString");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetDeviceUSBInfo(void) {
    log_call("ANT_GetDeviceUSBInfo");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetDeviceUSBPID(void) {
    log_call("ANT_GetDeviceUSBPID");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetDeviceUSBVID(void) {
    log_call("ANT_GetDeviceUSBVID");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetMessage(void) {
    log_call("ANT_GetMessage");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_GetNumDevices(void) {
    log_call("ANT_GetNumDevices");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_Init(void) {
    log_call("ANT_Init");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_InitCWTestMode_RTO(void) {
    log_call("ANT_InitCWTestMode_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_LoadCryptoKeyNVMOp_RTO(void) {
    log_call("ANT_LoadCryptoKeyNVMOp_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_OpenChannel_RTO(void) {
    log_call("ANT_OpenChannel_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_OpenRxScanMode_RTO(void) {
    log_call("ANT_OpenRxScanMode_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_RSSI_SetSearchThreshold_RTO(void) {
    log_call("ANT_RSSI_SetSearchThreshold_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_RequestMessage(void) {
    log_call("ANT_RequestMessage");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_RequestUserNvmMessage(void) {
    log_call("ANT_RequestUserNvmMessage");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_ResetSystem(void) {
    log_call("ANT_ResetSystem");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_RxExtMesgsEnable_RTO(void) {
    log_call("ANT_RxExtMesgsEnable_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_Script_Clear_RTO(void) {
    log_call("ANT_Script_Clear_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_Script_Dump_RTO(void) {
    log_call("ANT_Script_Dump_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_Script_EndSector_RTO(void) {
    log_call("ANT_Script_EndSector_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_Script_Lock_RTO(void) {
    log_call("ANT_Script_Lock_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_Script_SetDefaultSector_RTO(void) {
    log_call("ANT_Script_SetDefaultSector_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_Script_Write_RTO(void) {
    log_call("ANT_Script_Write_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SendAcknowledgedData_RTO(void) {
    log_call("ANT_SendAcknowledgedData_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SendAdvancedBurstTransfer_RTO(void) {
    log_call("ANT_SendAdvancedBurstTransfer_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SendBroadcastData(void) {
    log_call("ANT_SendBroadcastData");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SendBurstTransfer_RTO(void) {
    log_call("ANT_SendBurstTransfer_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SendExtAcknowledgedData_RTO(void) {
    log_call("ANT_SendExtAcknowledgedData_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SendExtBroadcastData(void) {
    log_call("ANT_SendExtBroadcastData");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SendExtBurstTransfer_RTO(void) {
    log_call("ANT_SendExtBurstTransfer_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetCWTestMode_RTO(void) {
    log_call("ANT_SetCWTestMode_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetCancelParameter(void) {
    log_call("ANT_SetCancelParameter");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetChannelId_RTO(void) {
    log_call("ANT_SetChannelId_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetChannelPeriod_RTO(void) {
    log_call("ANT_SetChannelPeriod_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetChannelRFFreq_RTO(void) {
    log_call("ANT_SetChannelRFFreq_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetChannelSearchTimeout_RTO(void) {
    log_call("ANT_SetChannelSearchTimeout_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetChannelTxPower_RTO(void) {
    log_call("ANT_SetChannelTxPower_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetCryptoID_RTO(void) {
    log_call("ANT_SetCryptoID_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetCryptoInfo_RTO(void) {
    log_call("ANT_SetCryptoInfo_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetCryptoKey_RTO(void) {
    log_call("ANT_SetCryptoKey_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetCryptoRNGSeed_RTO(void) {
    log_call("ANT_SetCryptoRNGSeed_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetCryptoUserInfo_RTO(void) {
    log_call("ANT_SetCryptoUserInfo_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetDebugLogDirectory(void) {
    log_call("ANT_SetDebugLogDirectory");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetLibConfig(void) {
    log_call("ANT_SetLibConfig");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetLowPriorityChannelSearchTimeout_RTO(void) {
    log_call("ANT_SetLowPriorityChannelSearchTimeout_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetNetworkKey_RTO(void) {
    log_call("ANT_SetNetworkKey_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetProximitySearch(void) {
    log_call("ANT_SetProximitySearch");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetSelectiveDataUpdateMask(void) {
    log_call("ANT_SetSelectiveDataUpdateMask");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetSerialNumChannelId_RTO(void) {
    log_call("ANT_SetSerialNumChannelId_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_SetTransmitPower_RTO(void) {
    log_call("ANT_SetTransmitPower_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_StoreCryptoKeyNVMOp_RTO(void) {
    log_call("ANT_StoreCryptoKeyNVMOp_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_USBReset(void) {
    log_call("ANT_USBReset");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_UnAssignChannel_RTO(void) {
    log_call("ANT_UnAssignChannel_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_WaitForMessage(void) {
    log_call("ANT_WaitForMessage");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD ANT_WriteMessage(void) {
    log_call("ANT_WriteMessage");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD FIT_AdjustPairingSettings_RTO(void) {
    log_call("FIT_AdjustPairingSettings_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD FIT_SetFEState_RTO(void) {
    log_call("FIT_SetFEState_RTO");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

__declspec(dllexport) DWORD getUnmanagedVersion(void) {
    log_call("getUnmanagedVersion");
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}
