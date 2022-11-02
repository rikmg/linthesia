// -*- mode: c++; coding: utf-8 -*-

// Linthesia

// Copyright (c) 2007 Nicholas Piegdon
// Adaptation to GNU/Linux by Oscar Aceña
// See COPYING for license information

#ifndef __TRACKSELECTION_STATE_H
#define __TRACKSELECTION_STATE_H

#include "SharedState.h"
#include "GameState.h"
#include "TrackTile.h"
#include "libmidi/MidiTypes.h"
#include "MidiComm.h"

#include <vector>

class TrackSelectionState : public GameState {
public:

  TrackSelectionState(const SharedState &state);

  std::unique_ptr<GameState> Clone() const override {
    return std::make_unique<TrackSelectionState>(*this);
  }

protected:
  virtual void Init();
  virtual void Update();
  virtual void Resize();
  virtual void Draw(Renderer &renderer) const;

private:
  void PlayTrackPreview(microseconds_t additional_time);
  std::vector<Track::Properties> BuildTrackProperties() const;

  int m_page_count;
  int m_current_page;
  int m_tiles_per_page;

  bool m_preview_on;
  bool m_first_update_after_seek;
  size_t m_preview_track_id;

  ButtonState m_continue_button;
  ButtonState m_back_button;

  ButtonState m_apply_all_not_played;
  ButtonState m_apply_all_played_auto;
  ButtonState m_apply_all_you_play;
  ButtonState m_apply_all_you_play_silent;
  ButtonState m_apply_all_learning;
  ButtonState m_apply_all_learning_silent;
  ButtonState m_apply_all_played_hidden;

  std::string m_tooltip;

  std::vector<TrackTile> m_track_tiles;

  SharedState m_state;
};

#endif // __TRACKSELECTION_STATE_H
