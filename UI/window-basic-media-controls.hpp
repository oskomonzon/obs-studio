#pragma once

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QTimer>
#include <obs.hpp>

class OBSBasic;

class OBSBasicMediaControls : public QDialog {
	Q_OBJECT

private:
	OBSBasic      *main;
	QSlider       *slider;
	QLabel        *timerLabel;
	QLabel        *durationLabel;
	QTimer        *timer;
	QPushButton   *playPauseButton;
	bool          isPlaying;
	OBSSignal     selectSignal;
	OBSSignal     removeSignal;
	OBSSignal     channelChangedSignal;

	QString FormatSeconds(int totalSeconds);
	void SetPlayPauseIcon();
	uint32_t GetMediaTime();
	uint32_t GetMediaDuration();
	void SetSliderPosition();
	void SetTimerLabel();
	void SetDurationLabel();
	void MediaSeekTo(int value);
	void StartTimer();
	void StopTimer();
	void ResetControls();

	static void OBSChannelChanged(void *param, calldata_t *data);
	static void OBSSceneItemSelect(void *param, calldata_t *data);
	static void OBSSceneItemRemoved(void *param, calldata_t *data);

private slots:
	void MediaPlayPause();
	void MediaRestart();
	void MediaStop();
	void MediaNext();
	void MediaPrevious();

	void MediaSliderChanged(int value);
	void MediaSliderReleased();
	void Update();

public:
	OBSSource     source;

	OBSBasicMediaControls(OBSBasic *parent, OBSSource source_);
	~OBSBasicMediaControls();

	void SetScene(OBSScene scene);
	void SetSource(OBSSource newSource);
};
