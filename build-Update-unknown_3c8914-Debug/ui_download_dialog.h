/********************************************************************************
** Form generated from reading UI file 'download_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_DIALOG_H
#define UI_DOWNLOAD_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *updater_icon;
    QWidget *progressFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *downloadLabel;
    QProgressBar *progressBar;
    QWidget *buttonFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *buttonSpacer;
    QPushButton *openButton;
    QPushButton *stopButton;

    void setupUi(QWidget *DownloadDialog)
    {
        if (DownloadDialog->objectName().isEmpty())
            DownloadDialog->setObjectName(QString::fromUtf8("DownloadDialog"));
        DownloadDialog->resize(464, 164);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DownloadDialog->sizePolicy().hasHeightForWidth());
        DownloadDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DownloadDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        widget = new QWidget(DownloadDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        updater_icon = new QLabel(widget);
        updater_icon->setObjectName(QString::fromUtf8("updater_icon"));
        updater_icon->setMinimumSize(QSize(72, 72));
        updater_icon->setStyleSheet(QString::fromUtf8("div.image {\n"
"	width:            72px;\n"
"	height:           72px;\n"
"	background-image: url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEcAAABHCAYAAABVsFofAAAAAXNSR0IArs4c6QAAKC1JREFUeAHtfHmAFNW571fVVdX7MtPds8MAwzLsewABAcUNcUEBI1nU6xrv07ybeLPcdyOYe31Xs94XTUxMjFuM0YlxRYOCILIp+zYIzMYw+9Ld03tXd1fd31c9DcMAXk00L3/ckxxOVXXVWX7n9y3nO2ck+p90XgSE8/7y/+EHXde5P0afalD6N5HQ3U06d6W2lvQ1awTtb9mtvxtw+oGhmhoSa/0kFFaQKdNNor2YlDIryW6Z5FQ4Ke+vbY5Hd7eF1qxZlPm8gfq7A2clwBkPcHoTdSZv1m5KWCyymJYVsyTKJrNottpFs9cqWPzmuKmtuTt58NDxukfuXZL6PID6uwbHbHJKmXhClvSsIuq6IpKu6LrZKphki8lisfo8isXvECwuPR5J94bqr180quWzBEn6LCv7rOty9IlC0iYK2TiJAmliViSTriZMWT1pokSfqTkoSK1mu+xy2EuHl5RWvrS3u1eKJfZeM29o22fRF/GzqCRfxx1rXrf9w8NbnPn7T1s+0K+M25y7Ba9VAqu7KRUXBdkkCEJWFTXKmDTBZBJETRI0zmkpHQtKPZ2t8t6D7dK+k1p52ue95udvH7/0vh+us3/a9ge//5czB5ZlRU2NWHnCbTFbHJcXV/ru9pV45u3d0fgmkX4dxmlYmcENfpr7uBk4iHExkSBREiQTOmvSKWvSM5pJE3VJ00mG/VJ0TZcy2ZgUTEal9wNWye3zTrx4+YXTLJ4PXvj322c1fpo2B777yXROzsQSgzHkZOkEb4nzxqKSgktQUVlrXU9BfW2Hua83TtMWVFFLQ2vrb/5j6ZBPCw5bK2bOOOQRu0lsKCYp2"
                        "BlUertSSkyNWeIqmYnSVlNWs2mayUZ62q7rZMtqmpWyuhlZBlgALAsMRdnicMmTq71itKv74D9ePuplEj79ZJ2fOejsfT962291uy9yv3Rkgc1unhDVxo/p0vt8x3e3Czt7jlOkL07ZbBqOSYY0LUNmy0iKRZJdA9H/pNcCpmnNmgfoF7RA8B/uFqiCqHyoX/A7rOLwEUWiy+c0pSXJdKI1LPV2xqQsMZEyYI4AJa3JmkAS6VkZ7Unoi5wMBeSde+LyiOH+C57e1lK+9Ve7fvn4nTPSn7Q//N55mKML339q3w9GjC79xoEdjUJbUy91tgSFdErFBxppeoZ0LU26nkUVmuGlCVCZy269lN5be+D1V5+88ZpPy5wzOw2RXVEjRqMOiQoDZi0RsytmcpeNKHGM/cJwm3+o39EXzdobWyJ2NamCSRoAAjjZrAQvUcZMydmsrnApiCappKJYGV1hDu3c3PDDn37jgsCZbZ3/7jzMEfSD+1+832KzTI5HEhe3HD8hZrOqAYYOKKAeMXaB/4+UK/nSZBJJTWfbz9/cJ/1F0OEMMvKc2YcJQ491XHXj896jB7cNczjMjvGzKuU5F0+Um7viUlNzSEqraRldkXUAQrogw+yDTQApo8ttJ1qVWMRbMWN+1YPf/NHG7/34vkU9n6Qn57VWNT9dmfjWyurLfEO8L825fAImBv3E2yIAgJYkEUwRucS9CSVr3wymS9fEk38da87XbUF//flVPZteu2uXNW1ft2vLycbHvlejNH14TLl84UilsNDOIiVj4gzGaBA1PSsoUDUKZTUl2NUp7znUWzRjwdiHVqx5UTlfKwOfnxec3EuCvqk5sKq0qnxr1YQRBigGMACEgWFRMjLuZbNMyRgmWZIAzuebampWZjfU3LTd4h/y5KHdrUd+tbpG8kmaMmf6EEXLABRBw+ChpAGUrpEZbOd7JdTTbT50LDBk6eI5P4IYnEelnO77fwMO0UXD3N9pawjMaWuKgCEmgzEsVgzS6SyQu9BJkWCMZJ"
                        "PcdLr6z/fq9ceviq+vuXntF2aPeWZDzQfh/RsOyIsXjJIlSQJ7BBn6kUGBmMGzhsnnsq21S2npTE57ZG39A/8dQB8Lzr0/3DjB4bR9Z/+OBlMWbqqhvg1gAHqeNSj52l9eSOFQlExm4cTnC8nZtX/3a3OarvzipEc7moKHX3tig3nRrOGyy21RNA3AaACGcsDAXTBErP5YiyJa5CX/8vPtF51d2+kn56XWHQ+94547f3zTn57Y4YmGeklLJ06Dw1/lFbJRCjT3sqnUVNuWFIKFBU89tSh5uonzXy28eaPFmm71ZTOaRxXSFjGri7AuuiBRkkz2PqvF2sPsOH8NZ/7CvtLt//vVlYFI6Kov/q8rlJ37WpVgKMoAIZOS1bJQ2DnAJPDrqmumWN559dCFj357XtuZNeXuzg0OGvn+03vXNB0N3N9S30rpVARvw0oxW/qBMUkmcnnsFApE8Eyga266mN5/Y++xFx5bWf1xCnnFiheVgJSo/mjX5u92tx9bJooZxVfs18vLSsjhdILpOiWTcYqn4kJbayBrtZasHz5m5oPkHr1r0ycE/fo7/nitnone9MV7Llc2bWtU1LgqM4t0KGa2ZjppEkBSzDa7NHV8yZa7L6+6CYM4y6M/Jzjf+PF7U0eNH/rBq8/ulNU4rB4ElkUqB46AARBd/dVFZLWbaefGQ9Tc0EGr7l5Crzy15a2Xn7jhynOBwyxp27/2/tbWg7dIIhXd8OVrxRkzJpHNYSVFNpPVolBFmYd6AgmKRJNwCTKUSCSpLxCgSE+b9nzN+mAkbnt9wtSrv/7Wc0tg2j8+XbLquZuL/aYvL735Yvnttw/L7CgyIPB9JFbQelaXMBHShQvHSY1H2m/+v1+btW5wjabBD5iatZ2JR7auOzYhHoa/pMMDBjA5E56zTnMvn0ahnj7avPbAhqkXTmxxuMxDSyr8wqHdzW8c2zdhUCO6MHmh6a6jO1/+g7dIXjp77mzHV265QagYWklpuLUpVaeKci+lMxmqPdpKHZ0hCkd"
                        "iFI8nKINnJcWFVD6kTJg8ZZzt3U07phzZv/m20VNvsI2/9YGtTZuePm9ksOHgS/tLKncOTUaj1XMWjZNPNPbAUQQg0D+8FjOuwaK2lpA0eVrl+C9fecHTNTU1Z7DnLIX8yz8dviCdomXhYJi0LEwz6xS2TFwKIqySizxeJ+3bcrxFtBX+w/btR6/xlhW/qcHbympUDzRPsfGyW18sLKu+9aWDezb+YvzUcZUzL5hLM2dPhz9E1BeOABiVRo3wUV1TF+061EkdvRkKhFNGDqFUMzrFkxk6Dg89DQf4//zrHVQ2rMLf11e/uvaZJzZedMMfqgZP7ul7QTd7/D85vPtkc2djh1JS5gV7mDk6lhlwFtmTJsGkplJisC8xIWSZsOr0t7mrM8Bh1niKXf98aGezmE3HAUq/KPWbbVmRaNnNF9G2t/boJqv7LijL5lf+c1lo3ZHOa/dub3pBkKSmvEgtWfVc5fuvPrW/o7trmat8nLByxRVgSBEASVMskYalNdH46gr6YH8L1Z8IUjSWpGg8RTHVQrGkQNGkTn6vmxpOhiiSyFJvMEFer4euu/4SmjpzuhBVE/O2vPPbPfOv//WkwYPK37Myt7v839/yxj7TrJlDFbNFYcYwSBJAMkH/IIammw7vPyG6Swrv5PHnv+XyDHDeeqvO2dIev6wH1Nawdso5eTlnj8115agyOrTrGAUC6VfWPr1ybb6iTYjn/r9vz181c8jBt/gZA/PntU/UqWZvhWgvpNlfGEU98IFSWQHAZCmZEWnKxErasuskdfUkoXx1SiDHUxrFEzFKZCx4x0QtnXGKJvAsqQEsjQ5+1E6XLppKy5fOhTErpKzicG1d//zeh37858n5vgwuX33y2lpVtz6+9vfvSaPHlDNjmDkmQdd57CYAIiaTKdOJlsD0F9YdmTrw+zPA6TAJ/9b4UbdF15I51oA6eZFS4AHPWjSB9m0+knZ7Su4dWEnuWsDuwBqNRem9d1/aItp8kqCYSLY6adSoSmrvgaKNZymWttHM"
                        "6aNp18EO6gwkcQ/A0iKyieKcVROYk2NJTziLZ4RnyAAvBjZV+J00f+ZI8vr8JNm9iMD7xDUPP/L+j361EVby3Emx2J6sO3DSVOKzSE6nnQExachgDoNkYmewqa5DMBUW/GAge06BwwjaCpxLO1oCYA1W32y2DdOd0zmwXnTsQBOpWfNzf/rNFa3n7oYuHP5g869VQayQ7U5SrG5SHB5YJCd1Y6ChuEgjhpdRU2ea6js0SgouSokFlJK8pCo+ZC+uPVhp2qii1EWBJJYkCNcw0xigJIA83hqmD49gW8LsIMXuIsVVSJrZ6Xzk0d89++KLh+ERn51e++01Ednlv3/bun1S1ahiBsMQJ7wpAiQBxljs7QmLyaw24QHohXwNp8B5ZVOTq+F4T3kywT4X+zT4yVDGrIgFGl5dToc/rI8UFg+7J69X8pXky6mX/ODOzkD7MhmAyDaXka02J2XA4K5QCmKlw/pYaM/hdkqk4c9gcyWV0QyznUplUOpQvDLExYXB2wGelVSLj5LmYsT/LDR31gh6Yd0x2n8sRA9+cwldc+l0WrxoBk2bMZF0SZj+zMtv/nu+L4PLdb+74anG2vZej1NGEAOUzgEEv4RVC8DSdPHwwZO+EW8enZb/9hQ4SS17W/1H3WZdz7GG8TNW3RAtf1kBqQmVouH0/ppfLIzlPx5Ysh/T2HD4u5hNwWx3G8AoNgfZXWCHZqJoRqIFc6ro1e1dFEqJYIeZ0oKZMiKCeCZkLIcyokRp6MQsQnrhBIOVJRXG2ux20oVzRtHrOwLUCQ9nWrWPbrhiMl06r5p21XbS8ZNRCiYlYfOOPXc+9szWooH9On0t6OmMuLW1vkOsHO4XoXsgUQaDDGA4nNDe0ismTOKa/DcGOCxnKcX69WgkDkCzBlPyq26oLqqeNIyOQ6QUl+fR87Gm7ciG+xWrMtTiLCAFbDFbQXurnSwOB4KWZioq9ZMKz/1kRKA4yqQgkyrKBiAaFrR6PpvgesH7ZpA0/F7kEmnBOCv9cVsPdQZVm"
                        "jx5OHWnzPTiu4309octCC7boNe4HQ9cO6vrp4+8+PRAdyI/UC5txb6HP9pdbxpS6UWMRYDOIRYvI7OwpBKq4Pa7l+CZjd83wOnrI4/TbS1LwiNlkTKAYTve7994fE5qbeoJJkb4X+KPBideEnT3nrzF5i4gr98PYOwAyE5wz1E6yOFy0OLZlfTse12kmmSAA8WLfRYYIACGDJoawVaIr4bsccg0e5STli8sIqtNpmff7aQIFPP1lw6juvYYPfrqUfrpa800Z854MjvdaIf1j5Ms0D+BcPSCq+54wzq4j3z/2mNXHwv2Juv0DCwAwU8HW1icWCEDEELAjMO8FAol/fy+AY4qpLzdHRHKplVYbJanXM75ORAB+B/pNO3etGYhR+bOSkFSx4iKUpQRLOTzFdAkKG+r3UYuiMO1F46gmxZX0sgKFwwn9AliPxk0C/UCHUSUgB5KwHtMadA96GAh9n2vmu2lyZU2eu9QH+1qiBIMFS2ZUUDvNqjU2IvoscVCKdTV0RPG+s5NtoIysgAgC8RZcPhcbU3HV5zVyf4HGTLt7m3vFZ0epyFWzDIGBpYLWaf6o23wq7TT4MQSKV9TXS+UEzTkKQvFkT6EIko8FOyGt0zi/vOJVGNT7b8UFhdBhzooGMuCBSZauqiall8yhm6/ajSNLnfQ+HIb+QvNpFgQE1LAEGxLmVB6XDKNGWKn+RM9tHhKAZX5LfTU5m5661CYjnap0E1Y8Y93096muOH3mN3YOLdaYAUtdKg5hjqtkPwUWd0+sjoLyV5QSi1t9d8Dm89aGnH/oYx3dbUGhIqKAogTHgAQBgbsMeA72dQltPbFJvCNEUPu6kuP7mwPwyxphr5hPcMMYitVMbyIAu0BXZItB/rBP6NgRXx4d82y0uJKsnsKIS4mmO0MbTrQTbMnKOSAWHAq91lo5dwiCsIRFKBosQOOoCF8HMhWfWeSth+PUlTNGn1kE9IaUqnQZaJKvw1OoU7N0DcS+iW5bLzXQZJVogi86mljSygQilEmhc"
                        "0th5tEm5WiPQ3D+7zwD4jO2gmRreY9gY4+YcyMsdxMDhSDOXypY0clRq09sSncZwOcjt74yFgEjgSSgA6wZBlrKTCnqLSAmg+fRBDL/JHxwqB/rFLAJ9tsSgYWp6QEPgu2jXrhrImY3cYg/Bl4uZMqXZj5GL2yN0hJLEHSMTC0f6a4Q2gNGdsHAIxLh1miIRCv+68po2NdKXr8vR6SzIYGgAaFWLktkFCwLynR+FE+2rK/FVFKnTIAXYIbYIXFxDqErdZZ4IC2dZFQr+B0KBijCJ+Od1LwJhL3hevoCsQNh9IApzuSquJVsWG++3VODhwRpthKcYQQFMF7zoBQVk974MvoVrtd6AimaORwD00sLaQPoSvi0HU7IA4HO9LQFSlYKKgd3uW1QAdC1zAQ3Cj/j684MUxVRQpdNtkNkExwOnVyOUwU5o/73zIhls5uWBpAs+fuQNgjgRFKJuyQCHGA4yAto3q4vsFpetnuwM6jQzgI5QITDEAgWNhhQgY43IpJEsv4O2M6TLKpjF9gHXNa5+TWVIokUQbL44yW7hvcEN+nVd0OyySYrYjLWMzUFkhRS2+Srpk7hKaM8FBVMRRrXcQQKwW+F2wENv9EUnBmQsHgOctgRe6eA/VYSkBRR5LQXehwE8RJB5v5uczv4jsTRFXAzMsWGTougyAZdJBVgZW0ITaE+m0WISubWKzOSmvWrIaK0YOIIuQmhZnLegeloZQZKEEw9vsN5kgmESRFMvQMirx3DNrxEgLfZsxuuLDnSFjFWcwQIQuyZDZDyaLD8QxtPtJL915ZRfNgkg+0Jwx9UeSWKIjFpQhfJiueNnxM1oEpgfvtzXHqCKepHfpLA6BSroeYPLAOwMAjht6RwagM2W0KJeNYOfCGMRauZpuN4085ZTew4v5r4JDCLhKYgoYGAsNAMUjwffhVAxzsNmUNMWJwmD0GSFzmauPbZMzaf9ffQn+hCZIqmzFzYI1kVqALIMvQGYgF05uHApQBwAVOmS6vxoJxuI0e2thFYfQ"
                        "BettIRqWnmzJmc1qFldYejUBBazQTlkwxq7l9VXzHSYBfgWAzwfHGEkRDFFHGOzKLA9BJkhUTJeqm0+jnPjv9LwxlPwinGZMHBmBhB9VoyQAHez2dxurbYAxjAzT6cwY+iCRDU8hpdqzOCnYjRhKVVRkBWVkwwIEYCjJn0diu3AJzy4rZD71xwTAHLZ9WSG0QhQOtceqD6BiqBxXznBTCzA+FaZ8Ms18LHaVA/KIY/IhiMzXDenH/mfUSzlqICKNmwR6eYraIIegfGUyyYNFqE9N6rFNFGPPcySQKDibNKVHqB4YxYV2IuF2MvzTA8Tks9TJmO4tVLzDJAYPeMosScACtVjPWQzI7Rr2Dm1OT4T4RR0UkiJOCLAIcHFAzvvU7FYpyg5jhV45FqBnKpKEPvjB0jxcgLBjlIhd8naZQmnohipcOs1O1z0zt0TQN9SrUiRBHO8RmaomVehhINM6dx+BIhzc7FD7R8uk+6ouk4DDKNGyIiw4f7aStH3TpiskSHNxXvl/xTzWWdEAs0NLY88+y69CvawA6+zxZkCGdzhhb2gY4/gJLvcNpplSsHxxMR168AvBCnV47dTclR6BuNueAz0hGuf6ZbwQXfO0X0H9wrxgc6BMRayPCrHqsiM0gWKXwDINJxwHMIgDwAcxzAD7NlrY42aBLXFC0ozHQqkKFFCjfCgB35WgXNULnRCBaeESLAeTJMBYaGIwVD2zwxieXWKi6zA4xsFE3gNywr526u6OgoYkadz9/zv3wRNxa4XJk5GhUBUNwGIInj4EB6AwU+3d+t+UYj5BZSYVO+SN/iUvPiRYe5OhjANSG+E5hkRu+vjqe30VicnNicPB9TzwZ6tzA33IY1chgjgKADEcPOx6QFrKCIez0JdCZCqdEPrdCbrsEywW/B0uKZjCjKYrgFhy+BijhI5EMheF/mAAqA8sWqxoAFgBw7nQQg9tRH6bGrgQ85Qid7ImTC2LltkPvCdR5dO8fGBx+NT+ZuMR+fiIxweN1UVdHFAsCKHtm"
                        "Tj8wrJyt+L600IHVQB4ch9I1bEShAQ4DkwOJWSRQD5YOvtICmCwVoUiWVKNBDPdUw2Lz7j8+iI17TWZQoG9kAKNAOUK4SIEIGDMNYGxmgRqwgmTR8eJ0iRPguOCzuGwSlLmJugDMpm6VtkNH8U4ZC34vnrUhtFoP1iSgfzohck29CbgMSQojTOjFIpVPd3SBZT0MKJ61Htr8E3zKUsjgcF/7+4t1lJqY4S31UNvJMEIjMMADgGGgsFzSK0utxmrAECszmQMlZU4c0kTcGS8bzMHAGBxedjgK2KmKIAgEr+k0KLjMpfZj7+1LxuNBUSzwSmAPTu0ZPhP7KTbMegKVyACLfRT2VXqxFK8uMNPxKJaBqJHb4VFY8HuLCo8V79pRB8d1MgAnneEtHKLGPoQsiq0UhM+DA6YGJfYilsPMiWAZwiClUql47bvP/hrVDWYND0yP9D4w0+2bJhyubcGYgB/aMPQOnEgWsYpKPzkdtg4eGVdA2GgMxGOpEPsqOSuFajDj+AfiC1FIpqmiqnyM01c9Aq8zoPnZyIOV7Gs99noGwMoAg5nD4sUz7YTYWMAoPv9oAxJ2DJyVNAqqAHusUM6c7ezgMcv4HoO34j73m2gAzCBb8VEada6a6iMH3jvWmTDiPl0AmfsJE0zxYPchCB1bVR5bPnM/0e9ic8mQYbMhpwAXaBsLTgYFmfUNVIMF3jaWJ4a+4o8ZEC0biv7S4YJjyGLFzh+X+JXLhuOdVD11uDi08qL7BjRofIt7dg4zNufor6dSaje/D9NvZF4wstiYMVgLBsPMMDIG2QlrUQH94egfdAHeyQIcM+4trK/wjpH5vv+dYoghHFZ64WDAiAVV+a2GeObPCKXSmWSwbu+X0B9Ef4x+ociLFInDx867efjYckdHawQLVQT2MEmG+Wa9g2ueWDWZ2uojglbvZw5fFJjEnw2r8sFny3nFBjgYKIPV2dlHXixASyqqLsWrrHd4JjhxJzjrbz2yJJzsSz4KM4iwANgDgBBTJDdWz2ZDF"
                        "7E+yukiBRaKB9QO8MbYwRCwqhDPsGA3rBVwJHgHhpXDyXVDfxWingLkdpj8bljADvhKE8vtNBZi5sEEpCEivSebXtj+2kN13DEk1jk8cWxADOaUlk+6rbSySDhR3wO3JWkwLW/KWbzcUB9Fdsv3MXbD6ORnn5YsHNY1YkRBh4wlgDF+hgDAMEgsYR1dEZoyb/KQkspFF+IXTuDlqdkxHmgHOx6MRRLbWFdIGBSDlGMLZpwBAwgyQOHZ5/ADg9cBgMbC+R4OVjnQEF4zdBb7Mjh/jHvBYJcfLAtBpBhUXr0LKI/2pGhLPc4NoX+xSKT+5M4Pvm505PQ/DA5PHlRHeXHVxLFjwxEE1rCJkOWFNlJepLisqi4Lti6bsMH4Af+cAgcgaJlYcmNJSSFjYoCSw4dvRGpq6KYZC8bTmAnXPkPk5u/ys5KvC3/UsTLbsu/ATZFIjFcIxgCCsDQ+6BbWCazHjONyBuAMvGEsyIfnCBVTMbQCV8zZ6APAY3D8ELk2KFwNxpKXDawb8uzcA0+7sTOSPPDWy1/dvf7hcy2OuZ/ZcbPueWHK3GozgnqUScZySph1DSaSgbEheOZ0WY+uzjENnwwAh2+ssdh3KquKIVpgIXpniBiXyMmkqjecCOiTLxjtqKiaMQt1GNTj7wYk4a3Hb2546aHbF0RiqrFCaYV5dUK5MtBMcOMjLo0Ma4SyA4qcQyrMHAtezL/DLxUCsE4sVvl7NqR8wcCZwRwXQAtHVX3db1Zft/3VB3fkfsW/Zya9sGTcsKrqoZMifVkKdoUQZUjmGGOAg5ZRL++wFNvl1Rir0TxXwZN0Kl19yZh2sxB/z+VxGoAYP3BPjA4JemNDl774+jnapJkrn1xyd03xqQ/PvBBbD2+rffb+L83tC+IwCTzcEPQED4bRwrqFMugUr4oNU42yDqw4AfO+F16uBXWVsZwAGN63ZQuYQsCZTboxy+g6e7HsP+1pDCVf/cm919a++8ImfCY6vaPHXHfHYw9i5/XUuC69b519yqy7Xp"
                        "l/5Uzxo0NdWJfC+esHJc8a7n5hifNQ3e4J6/k6n05Vwg8YtXdeeek/x08aojNbOBvTxGjCUqbTaW3rtkbt4utnK1ow9T2MAC+ckfielZ/SemBr/W/vW76s6ciRI21YNrAmQwgFg8TaBYCpsFa8icdlggHEdR8AYvFphyiWoZaZUNZMF5z8Mr5jt4T/HA1rWAp1tLU88Z2v3nJ482sfoGp2L0TFbK+YeeHMb7kmrfxt7m8fsP/S0fONafPHjTxysAtnFkNQxIl+cHLixAyuHFWiH9237beD/9iNB3JGqt21sW7R0uULIwnTsAx6Az0BzxnnxAEQl4lEKj1m4jA1HQ+PLqjY01m3/4/52HIeGO4oY2GN9Hakd697Hvvm7gJPxehKm1mWWIyYxtwpEOlUZsaEmSEAIAlAIrj2gEHsSOJYqDF6Ac9JVTOHNr2x9Qf33PivHU21x/GZoVNQakUlk6cvWrZseevJ6OSSCu8ET+kOzWXVHhk1eaS4f8dJUuNBAIPFJpiT7wPP/7Ax/sYnH77/VoTYDOWNuox0Fjh4KnS1t7SuuO3WLzU1dMHlYVBAEWYPzqihn+nWlnB6weVT1ObD9bNGTP3ypqO7/9DN3yEzE/Pg8MaYXctkLMe2v1O37fU/7C8aOaXS6ixwmHAgj+O2bEbZI2dGYUefotAthriBKSx+7RCzFugsdvI6emPpo4drOx6+89qfrXv+139Wk3FWvnmLyYPKDBk5/7L5Sy65eOv6I4KaTFdPnFa2vHxkqbjpzeMABroG5ptnxYgZcwmsq6cN17evf+qbbY0f7EEdeHI68UDOSvu3vbOjdsfGF5ye4V+MhqMQKRYrgUnNewcYTiazZXtT5trbLtJ/96O1j62448Wrax5fGe6viEEamAEDpSLdba2P3LnkEZx48H1h6Y3Tl9zx7Xm+0jJsZvESQqRARhAgXTmnDEZERpNJtNYXCCbefvbnH773+59vVeNRnoQgMk5vGjp8YDvk8Q0byfKfxU5Ew2GIUSgKm4L9dui"
                        "ZdAq6hoc+EBxgYbHrh3a+W/MafjkrceWDEz+ze4rKq57ZXLvrtVd2Y/GagRUV02BRGqY4BVOawJ89JQv9hckp1d7k73+2tvf9d354T6jjoxZ8y+FJDow5kDF44nisHZmfceZrO+pwOD2+QmdRscfm8DichUU2xIJwpDerxfp6Ewlo83BvV1840BUA+/LrUF4WcGZweF3KnixPCpexpV/55YbLblg8543ntsAixQAT/oddES2T6hcnvGUwhoVAoAuvmqH/6vs3LWw/eZxX4dwGT+SpdC7mML6ZUFdr9+rbb/jKrff//IldOxtZNBFKhd8GKYAaZgZlgr2hzMHjUvor37wK2+LKD7euf+onrXUbmJ5Mc5yZMwbCYIN1hgjwoHggOCOsKX2BrhZkBH8NQFkk+V1unzvJdXBm0eG6uMzf8751HiD+jZ/rbrdneBDxHFgOgMFiAwpmgGU/IEbN/dfDxg/V3n31ydUApgHfst46Q6Rwf2oZwNeDk9TRXBeoGjfBP3Tk2DGBQAxrY3RCFKB3BLCINyPFVDKRULvDYurSa6ZlLVL5tEhYyfa0t6BBKIzcILnMDyo/0PzA8jPP+iPUn1lsOPM9P2dm5JnD7xssQcnMybNIhQdsnzJ/2Wo1JYhdbZ2nlO4pYDB24GIA5S/DzqgnvvlPv1n9IJ5wX7ge7ucZ6VwKmV/Io2j+cMPrWy+79tqpkq2gKBZLQjMwODg9wtkkpnCfVNNJtbUnm5q3aFyisqqqXM8Ore5qOX4onQ5xozwrg8Hhmc9nfocHmheTPAB5ELjkd/LlQFDyjMrYPKUjZy28+mtd7XEhEmKrBPLltH4/YRgcWD4c6Z00d3jrY/d/aTlEmPvFwHM9+THjMpfOBw7/ytRmmls2v/HyO6vuuv2iYFizYOXLFSLajAEj1AI9AYDEpJ5RU+29yaSndEjiyuumYPt4ZLVJGe1pa/qoDmPLWxUu8+xhcLhTPHODM4PBefBzvudv8qBwX3jGdVfh6NlzFi+5oelYQEjHIwYQ"
                        "edYwKPlr7MGRw+12Dq0e56ndtWEtvmXQz2INnn2sWDGSDBD/rZX04bq3Nq/6xzvmB4KqCfjw4WQDJPyFCoflVfwJJmJamUQ4nEh0x0zxCXPGJS5cNF4sKJpaLtJQWzSb6VMjrTzreTHj7/Ng5QEbXA4Ggr9hJnLmerh/xox7iydfMmvxJVfUHWwX+CSssdo2MME/rH8Mp4q/0KmnvU/wYhk6feHFY/dtfeOP/XWhODN9HHP4Te4Ad8QUi/Vltq5/ZfOXbr1lJk5qKfE4zqtAtDApAIfjjXoKBgDnc/W4ChexL5yMxwRXYuzMMck5Cyboo6pnO53e6fhj2TLSHNZsvNeMgQYGDjR/PbDMt89lPjMg+WwAg3uxvPKCFVPnz51Td6gVK2h4wQZbckEsgzUMDp7xcz71JiNXjh45evSUhWP3bnnlddTB7Z6RzmWtzngBNzybrCC1QGurds/Sefc+8FTNtxyVJZVNJxDsBTBoN6tjEYQ1E7asjAO+EOZsuq9XTcUjrpTsdqnF06alvrpwCqm9V5gbjjcL3ceCSqi5Jd3aGlC7uw9rfn+3tmmTHyOo4fbzgx58fa57fiY4CrylaN6YJz4tnsMGoVPEQGxuOzk9NirwezSLQ2xLJgK1yVhsT/3RQ+9ufv/xbfieRfys9EnA4Y7mAVJVNer67qor/u2fHnr85omTL5h45Gh3Gt4sfFtNFXU1m8pCwjL4Q3D8VaGcNWtYR2VNaiSd7DOnAzZXhpSSjFJVlJ00MZ0po4KMw0t0rJf0gumkLwQoq5ENb/ysrn78A7e3pEzFHhfHpGW7BQtJD5WNKErY3XIIvlLbwV3vr39v7Ztru9sbG1BTXtmfxZaBrbDC/TSJfRFeN7FjZ52xaOn4f/7pr76ycfPRCA43xrDFHMV/PyCKnWY4GxpOMogRhOTDsmKJyIIS1W3WhNUi4Siki7eQ02m/LzMc58ED+OPncfivnaxYYYgL1Bnc40+XpGW3/eydy1ZcuUBNpVMHPty6fuvaZ5+rR3QAs"
                        "5mvievkzCLJD9lFYFeB9do506cFJ18JM47XilZv2TDv7d/9jyvKxkwuPljbGsUmYhRL5whozeuOCCw/tgqlmCioMexLIMAp8InblO52pN19YsZd4c5SbRc6vFBbs9qQhr8EHMXhKBwpWc2+WKgnjOgBD55BYD3FSnxgzus0/o2v+b1zpr8UHK6Mv2WFzh6uMm3epVXL7/jmFARVlMaWEJiUiYhgEixZDP+xl3hGMCWEjM77/imTFFdtiicTxyEtRXVmj7VHIFJ/FTi8ZOFlCZf5QfPA+ZozA5BnY77Eo49Pfw04A2tmcWOg5EVX3Th84XVfLFPcFaau3kgsFE3G5KyAU/taEjtNqaQsqVlNTdvN2Yw5ZcqmzEVasKBBq1mxwphB7vlfIFbcl4Fj+cQA8IfnSwMrPN87n/a5sUYaMX2x45a77i4rLK2k7j4t1RuPqlEEg/SsNY3jNKdYUwbWrFm9kGfXSH8FOPkqPrPy8wDnrM6NX7FCuW3V3bby0SNF/AVxuq8tkAnTmbom/9HfEzj5Pv3NSjhhfO5XWLPGODluXOefcfk368j/NPTXIfBfSeYtjgUVOCUAAAAASUVORK5CYII=');\n"
"}\n"
""));
        updater_icon->setPixmap(QPixmap(QString::fromUtf8(":/icons/update.png")));

        horizontalLayout->addWidget(updater_icon);

        progressFrame = new QWidget(widget);
        progressFrame->setObjectName(QString::fromUtf8("progressFrame"));
        verticalLayout_2 = new QVBoxLayout(progressFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        downloadLabel = new QLabel(progressFrame);
        downloadLabel->setObjectName(QString::fromUtf8("downloadLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        downloadLabel->setFont(font);

        verticalLayout_2->addWidget(downloadLabel);

        progressBar = new QProgressBar(progressFrame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(320, 0));
        progressBar->setValue(0);
        progressBar->setInvertedAppearance(false);

        verticalLayout_2->addWidget(progressBar);


        horizontalLayout->addWidget(progressFrame);


        verticalLayout->addWidget(widget);

        buttonFrame = new QWidget(DownloadDialog);
        buttonFrame->setObjectName(QString::fromUtf8("buttonFrame"));
        horizontalLayout_2 = new QHBoxLayout(buttonFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, 12, 12, 12);
        buttonSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(buttonSpacer);

        openButton = new QPushButton(buttonFrame);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        horizontalLayout_2->addWidget(openButton);

        stopButton = new QPushButton(buttonFrame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout_2->addWidget(stopButton);


        verticalLayout->addWidget(buttonFrame);


        retranslateUi(DownloadDialog);

        QMetaObject::connectSlotsByName(DownloadDialog);
    } // setupUi

    void retranslateUi(QWidget *DownloadDialog)
    {
        DownloadDialog->setWindowTitle(QApplication::translate("DownloadDialog", "Software Updater", 0, QApplication::UnicodeUTF8));
        updater_icon->setText(QString());
        downloadLabel->setText(QApplication::translate("DownloadDialog", "\344\270\213\350\275\275\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("DownloadDialog", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("DownloadDialog", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DownloadDialog: public Ui_DownloadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_DIALOG_H
