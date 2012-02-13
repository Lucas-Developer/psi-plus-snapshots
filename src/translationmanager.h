/*
 * translationmanager.h
 * Copyright (C) 2006  Remko Troncon, Justin Karneges
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#ifndef TRANSLATIONMANAGER_H
#define TRANSLATIONMANAGER_H

#include <QObject>

class VarList;
class QTranslator;

class TranslationManager : public QObject
{
	Q_OBJECT

public:
	static TranslationManager* instance();

	VarList availableTranslations();
	const QString& currentLanguage() const;
	QString currentXMLLanguage() const;
	void loadTranslation(const QString& language);

protected:
	QStringList translationDirs() const;
	bool loadQtTranslation(const QString& language);

private:
	TranslationManager();
	~TranslationManager();

	QString currentLanguage_;
	//QString currentLanguageName_;
	QTranslator* translator_;
	QTranslator* qt_translator_;

	static TranslationManager* instance_;
};

#endif
