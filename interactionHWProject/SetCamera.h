#ifndef _SET_CAMERA_H
#define _SET_CAMERA_H

void SetCamera(FbxScene* pScene, 
               FbxTime& pTime, 
               FbxAnimLayer* pAnimLayer,
               const FbxArray<FbxNode*>& pCameraArray,
               int pWindowWidth, int pWindowHeight);

FbxCamera* GetCurrentCamera(FbxScene* pScene); //현재 카메라 정보 Get

void CameraZoom(FbxScene* pScene, int pZoomDepth, int pZoomMode);
void CameraOrbit(FbxScene* pScene, FbxVector4 lOrigCamPos, double OrigRoll, int dX, int dY);
void CameraPan(FbxScene* pScene, FbxVector4 lOrigCamPos, FbxVector4 lOrigCamCenter, 
			   double OrigRoll, int dX, int dY);

#endif // #ifndef _SET_CAMERA_H






