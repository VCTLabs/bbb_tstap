/*
 * Copyright (c) 2014, Jumpnow Technologies, LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "tstap.h"
#include <qdebug.h>
#include <qevent.h>
#include <QtWidgets/qboxlayout.h>

TsTap::TsTap(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

	layoutWindow();

	connect(m_exitButton, SIGNAL(clicked()), SLOT(close()));
}

void TsTap::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "Down : " << event->pos().x() << event->pos().y();
}

void TsTap::mouseReleaseEvent(QMouseEvent *event)
{
	qDebug() << "Up   : " << event->pos().x() << event->pos().y() << "\n";
}

void TsTap::layoutWindow()
{
	m_exitButton = new QPushButton("Exit");
	m_exitButton->setMinimumSize(60, 40);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addStretch();
	layout->addWidget(m_exitButton);
	layout->addStretch();

	QWidget *widget = new QWidget;
	widget->setLayout(layout);

	setCentralWidget(widget);
}

