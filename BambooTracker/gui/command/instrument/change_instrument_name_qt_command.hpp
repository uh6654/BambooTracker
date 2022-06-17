/*
 * Copyright (C) 2018-2022 Rerrah
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef CHANGE_INSTRUMENT_NAME_QT_COMMAND_HPP
#define CHANGE_INSTRUMENT_NAME_QT_COMMAND_HPP

#include <memory>
#include <QUndoCommand>
#include <QString>
#include <QListWidget>
#include "gui/instrument_editor/instrument_editor_manager.hpp"

class ChangeInstrumentNameQtCommand final : public QUndoCommand
{
public:
	ChangeInstrumentNameQtCommand(QListWidget* list, int num, int row,
								  std::weak_ptr<InstrumentEditorManager> editorMan,
								  const QString& oldName, const QString& newName,
								  QUndoCommand* parent = nullptr);
	void undo() override;
	void redo() override;
	int id() const override;

private:
	QListWidget *list_;
	const int num_;
	const int row_;
	std::weak_ptr<InstrumentEditorManager> editorMan_;
	const QString oldName_, newName_;
};

#endif // CHANGE_INSTRUMENT_NAME_QT_COMMAND_HPP
