/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Flacon - audio File Encoder
 * https://github.com/flacon/flacon
 *
 * Copyright: 2012-2013
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef INPUTAUDIOFILE_H
#define INPUTAUDIOFILE_H

#include <QString>
#include <QList>

class InputAudioFormat
{
public:
    InputAudioFormat(const QString &name, const QString &ext, const QString &program);

    QString name() const { return mName; }
    QString ext() const { return mExt; }
    QString program() const { return mProgram; }

    static QList<InputAudioFormat> allFormats();
private:
    QString mName;
    QString mExt;
    QString mProgram;
};

class InputAudioFile
{
public:
    InputAudioFile(const QString &fileName);

    QString fileName() const { return mFileName; }
    bool isValid() const { return mValid; }
    bool isCdQuality() const { return mCdQuality; }
    int sampleRate() const { return mSampleRate; }


private:

    QString mFileName;
    bool mValid;
    QString mErrorString;
    int mSampleRate;
    bool mCdQuality;

    bool load();
};

#endif // INPUTAUDIOFILE_H
